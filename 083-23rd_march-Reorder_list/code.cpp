#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow->next;
        slow->next = nullptr;

        ListNode *prev = nullptr;
        for (ListNode *current = mid; current != nullptr;)
        {
            ListNode *tmp = current->next;
            current->next = prev;
            prev = current;
            current = tmp;
        }

        ListNode *current = head;

        while (prev != nullptr)
        {
            ListNode *tmp1 = current->next;
            ListNode *tmp2 = prev->next;
            current->next = prev;
            prev->next = tmp1;
            prev = tmp2;
            current = current->next->next;
        }
    }

private:
    void print(ListNode *node)
    {
        while (node != nullptr)
        {
            std::cout << node->val << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }
};