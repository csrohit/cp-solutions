#include <cstdio>
#include "linkedlist.h"

ListNode *swap(ListNode *head, int k)
{
    ListNode  dummy(0, head);
    ListNode *front    = &dummy;
    ListNode *rearPrev = &dummy;

    for (int idx = 0; idx < k; ++idx)
    {
        front = front->next;
    }

    while (front->next)
    {
        front    = front->next;
        rearPrev = rearPrev->next;
    }
    printf("%d th node from last %d\n", k, rearPrev->val);
    rearPrev->next = rearPrev->next->next;

    return head;
}

int main()
{
    LinkedList list;
    for (int i = 1; i < 6; ++i)
    {
        list.insert(i);
    }

    int n = 1;
    list.print();
    list.head = swap(list.head, n);
    list.print();

    return 0;
}
