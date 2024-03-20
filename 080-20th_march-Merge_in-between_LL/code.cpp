#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *prev = list1;  // Initialize pointers to traverse list1
        ListNode *temp1 = list1; // Modified variable name
        ListNode *curr = list1;
        a--; // Adjust a to match zero-based indexing

        // Traverse list1 to find the node at position (a-1)
        while (temp1 != NULL && a--)
        {
            temp1 = temp1->next;
            prev = temp1;
        }

        temp1 = list1; // Reset temp1 to traverse list1 again

        // Traverse list1 to find the node at position (b+1)
        while (temp1 != NULL && b--)
        {
            temp1 = temp1->next;
            curr = temp1;
        }

        ListNode *temp2 = list2; // Initialize pointer to traverse list2

        // Traverse list2 to find the last node
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }

        prev->next = list2;       // Connect the node before position 'a' to the head of list2
        temp2->next = curr->next; // Connect the last node of list2 to the node after position 'b'

        return list1; // Return the head of list1
    }
};