#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *head_cpy = head;
        ListNode *dummy_head = head;
        int length = 0;
        while (head_cpy != NULL)
        {
            length++;
            head_cpy = head_cpy->next;
        }
        if (n == length)
        {
            return head->next;
        }
        int delete_target = length - n;
        while (delete_target != 1)
        {
            head = head->next;
            delete_target--;
        }
        head->next = head->next->next;

        return dummy_head;
    }
};