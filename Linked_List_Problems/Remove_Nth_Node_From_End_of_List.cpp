#include <iostream>
#include <vector>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        ListNode* prev=head;
        int count =0;
        while (curr!=nullptr)
        {
            count++;
            curr=curr->next;
        }
        curr=head;
        for (int i = 0; i < (count-n); i++)
        {
            prev=curr;
            curr=curr->next;
        }
        curr=curr->next;
        prev->next=curr;

        
        return head;
    }
};

// Helper function to create a linked list from a vector
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

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << " -> "; // For better readability, print an arrow between nodes
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    
    ListNode* head = createList({1, 2, 3, 4});
    cout << "Original List: ";
    printList(head);
    
    head = sol.removeNthFromEnd(head, 2);
    
    cout << "Modified List after removing 2nd node from the end: ";
    printList(head);

    // Test case 2: Create a list [5] and remove the 1st node from the end
    head = createList({5});
    cout << "\nOriginal List: ";
    printList(head);
    
    head = sol.removeNthFromEnd(head, 1);
    
    cout << "Modified List after removing 1st node from the end: ";
    printList(head);

    // Test case 3: Create a list [1, 2] and remove the 2nd node from the end
    head = createList({1, 2});
    cout << "\nOriginal List: ";
    printList(head);
    
    head = sol.removeNthFromEnd(head, 2);
    
    cout << "Modified List after removing 2nd node from the end: ";
    printList(head);

    return 0;
}
