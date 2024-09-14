#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        int count=0;
        ListNode *curr=head;
        ListNode *result = nullptr;
        vector<int> v;
        while (curr != nullptr)
        {
            v.push_back(curr->val);
            curr=curr->next;
        } 
        int vec_size=v.size();

        curr=head;
        for (int i = 0 ; i<v.size()/2;i++)
        {
            curr->val=v[i];
            curr=curr->next;
            curr->val=v[v.size()-i-1];
            curr=curr->next;
        }

        if((v.size()%2)!=0)
        {
            curr->val=v[v.size()/2];
        }
    }
};
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    
    Solution sol;
    ListNode* head = createList({1,2,3,4});
    sol.reorderList(head); 
    while (head) {
        cout << head->val << " ";
        head = head->next;
        cout << endl;
        }
    return 0;
}