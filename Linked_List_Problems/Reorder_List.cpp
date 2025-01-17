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
        while (curr != nullptr)
        {
            count++;
            curr= curr->next;
        }
        count=count/2;
        curr=head;       
        for (int inc = count ,dec=count; dec==0;inc++,dec--)
        {
            int local_count1=0;
            int local_count2=0;
            while (local_count1!=inc || local_count2!=dec)
            {
                curr=curr->next;
            }   
            if(local_count1==inc)
            {
                result=curr;
            }
            else if(local_count2==dec)
            {
                head->next=curr;

            }
        }
        // return 0;
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

vector<int> listToVector(ListNode* head) {
    vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

void testReorderList(const vector<int>& input, const vector<int>& expected) {
    Solution sol;
    ListNode* head = createList(input);
    sol.reorderList(head);
    vector<int> result = listToVector(head);
    if (result == expected) {
        cout << "Test passed!" << endl;
    } else {
        cout << "Test failed. Expected: ";
        for (int val : expected) cout << val << " ";
        cout << "but got: ";
        for (int val : result) cout << val << " ";
        cout << endl;
    }
}
int main() {
    testReorderList({1, 2, 3, 4}, {1, 4, 2, 3});
    testReorderList({1, 2, 3, 4, 5}, {1, 5, 2, 4, 3});
    
    return 0;
}
