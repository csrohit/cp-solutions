#include <cstdio>
#include <unordered_map>
#include <iostream>

using std::unordered_map;
using std::cout;
using std::endl;

class Node
{
  public:
    int key;
    int value;

    Node *next;
    Node *prev;
    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {};
};

/* new node to be added to tail */
class LRUCache
{
  private:
    unordered_map<int, Node *> cache;
    int                        capacity;
    Node                      *head;
    Node                      *tail;

    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next       = nullptr;
        node->prev       = nullptr;
    }

    void add(Node *node)
    {
        Node *tmp  = head->next;
        tmp->prev  = node;
        head->next = node;
        node->prev = head;
        node->next = tmp;
    }

  public:
    LRUCache(int _capacity) : capacity(_capacity)
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    };

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }
        Node *node = cache[key];
        remove(node);
        add(node);
        return node->value;
    }

    void put(int key, int value)
    {
        Node *node = nullptr;
        if (cache.find(key) != cache.end())
        {
            node = cache[key];
            // printf("Updating node %d->%d with node: %d->%d\n", node->key, node->value, key, value);
            remove(node);
        }
        else
        {
            if (cache.size() >= capacity)
            {
                /* cache is full */
                node = tail->prev;
                // printf("Replacing node %d->%d with node: %d->%d\n", node->key, node->value, key, value);
                remove(node);
                cache.erase(node->key);
            }
            else
            {
                node = new Node(key, value);
                // printf("Adding a new node: %d->%d\n", key, value);
            }
            cache[key] = node;
        }
        node->key   = key;
        node->value = value;
        add(node);
    }

    void print()
    {
        Node *node = head->next;
        printf("\nCache:\n");
        while (tail != node)
        {
            printf("%d -> %d\n", node->key, node->value);
            node = node->next;
        }
    }
};

int main()
{
    LRUCache cache(2);

    cache.print();
    cache.put(1, 1);
    cache.print();
    cache.put(2, 2);
    cache.print();
    cout << cache.get(1) << endl;
    cache.print();
    cache.put(3, 3);
    cache.print();
    cout << cache.get(2) << endl;
    cache.print();
    cache.put(4, 4);
    cache.print();
    cout << cache.get(1) << endl;
    cache.print();
    cout << cache.get(3) << endl;
    cache.print();
    cout << cache.get(4) << endl;
    cache.print();
    return 0;
}
