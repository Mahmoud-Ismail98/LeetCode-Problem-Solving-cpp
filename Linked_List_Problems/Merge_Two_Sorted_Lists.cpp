#include <iostream>
#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* Head=nullptr;
        ListNode* Curr=nullptr;
        if(list1==NULL && list2 !=NULL)
        {
            return list2;
        }
        else if (list2==NULL && list1 !=NULL)
        {
            return list1;
        }
        if(list1==NULL && list2 ==NULL)
        {
            return NULL ;
        }
        if (list1->val<=list2->val)
        {
           Head=list1;
           list1=list1->next;
        }
        else
        {
           Head=list2;
           list1=list2->next;
        }
        Curr=Head;
        while (list1!=NULL && list2!=NULL)
        {
            if (list1->val<list2->val)
            {
                Curr->next=list1;
                list1 =list1->next;
            }
            else
            {
                Curr->next=list2;
                list2=list2->next;
            }
            Curr=Curr->next;
        }
        if (list1==NULL)
        {
            Curr->next=list2;
        }
        else
        {
            Curr->next=list1;
        }
        return Head;
        
        
    }
};

// Helper function to print the linked list
void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Test case function
void testMergeTwoLists() {
    Solution solution;

    // Test case 1
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);
    std::cout << "Merged list 1: ";
    printList(mergedList); // Expected output: 1 1 2 3 4 4

    // Test case 2
    list1 = nullptr;
    list2 = nullptr;
    mergedList = solution.mergeTwoLists(list1, list2);
    std::cout << "Merged list 2: ";
    printList(mergedList); // Expected output: (empty)

    // Test case 3
    list1 = nullptr;
    int arr3[] = {0};
    list2 = createList(arr3, 1);
    mergedList = solution.mergeTwoLists(list1, list2);
    std::cout << "Merged list 3: ";
    printList(mergedList); // Expected output: 0
}

int main() {
    testMergeTwoLists();
    return 0;
}
