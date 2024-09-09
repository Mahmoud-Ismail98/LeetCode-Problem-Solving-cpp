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
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = curr->next;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main() {
    // Test case 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    // Test case 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    // Test case 3 (empty list)
    ListNode* head3 = nullptr;

    Solution solution;

    // Reverse the lists
    ListNode* reversed1 = solution.reverseList(head1);
    ListNode* reversed2 = solution.reverseList(head2);
    ListNode* reversed3 = solution.reverseList(head3);

    // Print reversed list 1
    std::cout << "Reversed list 1: ";
    while (reversed1 != nullptr) {
        std::cout << reversed1->val << " ";
        reversed1 = reversed1->next;
    }
    std::cout << std::endl;

    // Print reversed list 2
    std::cout << "Reversed list 2: ";
    while (reversed2 != nullptr) {
        std::cout << reversed2->val << " ";
        reversed2 = reversed2->next;
    }
    std::cout << std::endl;

    // Print reversed list 3
    std::cout << "Reversed list 3: ";
    if (reversed3 == nullptr) {
        std::cout << "Empty list";
    }
    std::cout << std::endl;

    return 0;
}
