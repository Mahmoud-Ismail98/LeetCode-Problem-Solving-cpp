#include <iostream>
#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode *curr=head;
    ListNode *prev=nullptr;
    ListNode *next=nullptr;
    while(curr!=nullptr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;  
    }
    return prev;
    }
};

int main() {
    // Test cases
    // Example 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    // Example 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    // Example 3
    ListNode* head3 = nullptr;

    Solution solution;

    // Test the reverseList function
    ListNode* reversed1 = solution.reverseList(head1);
    ListNode* reversed2 = solution.reverseList(head2);
    ListNode* reversed3 = solution.reverseList(head3);

    // Output the reversed lists
    std::cout << "Reversed list 1: ";
    while (reversed1 != nullptr) {
        std::cout << reversed1->val << " ";
        reversed1 = reversed1->next;
    }
    std::cout << std::endl;

    std::cout << "Reversed list 2: ";
    while (reversed2 != nullptr) {
        std::cout << reversed2->val << " ";
        reversed2 = reversed2->next;
    }
    std::cout << std::endl;

    std::cout << "Reversed list 3: ";
    while (reversed3 != nullptr) {
        std::cout << reversed3->val << " ";
        reversed3 = reversed3->next;
    }
    std::cout << std::endl;

    return 0;
}
