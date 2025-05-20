#include <cstdio>
#include "linkedlist.h"

ListNode *swap(ListNode *head, int k)
{
    ListNode *front     = head;
    ListNode *rear      = head;
    ListNode *fromStart = nullptr;

    for (int idx = 0; (idx < k - 1) && front; ++idx)
    {
        front = front->next;
    }

    fromStart = front;
    
    while (front->next)
    {
        front = front->next;
        rear = rear->next;
    }
    printf("%d th node from start %d, last %d\n", k, fromStart->val, rear->val);

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
