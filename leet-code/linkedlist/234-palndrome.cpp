#include <cstdio>
#include "linkedlist.h"

bool isPalindrome(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle node is %d. %d\n", slow->val, slow->next->val);

    return false;
}

int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(4);
    list.insert(3);
    list.insert(2);
    list.insert(1);

    isPalindrome(list.head);

    return 0;
}
