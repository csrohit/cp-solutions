#ifndef _LIST_H_
#define _LIST_H_

#include <cstdio>
class ListNode
{
  public:
    int       val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int _val) :val(_val), next(nullptr) {};
    ListNode(int _val, ListNode *_next) : val(_val), next(_next) {};
};

class LinkedList
{
  private:
    ListNode *tail;

  public:
    ListNode *head;

    LinkedList() : head(nullptr), tail(nullptr) {};

    void insert(int val)
    {

        ListNode *newNode = new ListNode(val);

        if (nullptr == head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail       = newNode;
        }
    }

    ~LinkedList()
    {
        ListNode *temp = head;
        while (temp)
        {
            ListNode *next = temp->next;
            delete temp;
            temp = next;
        }
    }

    void print()
    {
        ListNode* node = head;

        while(node)
        {
            printf("-> %d ", node->val);
            node = node->next;
        }
        printf("\n");
    }

};

#endif // !_LIST_H_
