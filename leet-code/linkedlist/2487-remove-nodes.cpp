#include <cstdio>
#include <limits>
#include "linkedlist.h"

ListNode *reverse(ListNode *head)

{
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr)
    {
        ListNode *next = curr->next;
        curr->next     = prev;
        prev           = curr;
        curr           = next;
    }
    return prev;
}
ListNode *removeNode(ListNode *head)
{
    /* reverse list */
    ListNode *curr = head;

    head = reverse(head);

    int maxNode = head->val;

    ListNode *prev = head;
    curr           = head->next;

    while (curr)
    {
        if (maxNode <= curr->val)
        {
            /* this is the max node observed till now, keep in list */
            maxNode = curr->val;
            curr    = curr->next;
            prev    = prev->next;
        }
        else
        {
            /* remove this node */
            ListNode *next = curr->next;
            delete curr;
            curr       = next;
            prev->next = curr;
        }
    }

    head = reverse(head);

    return head;
}

int main()
{

    LinkedList list;
    list.insert(5);
    list.insert(2);
    list.insert(13);
    list.insert(3);
    list.insert(8);

    list.print();

    list.head = removeNode(list.head);
    list.print();

    return 0;
}
