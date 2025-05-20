#include <cstdio>
#include <queue>
#include "libs/tree/bst.h"

using std::queue;
using std::vector;

class Solution
{
  private:
    struct Record
    {
        int            data;
        int            level;
        TreeNode<int> *parent;
    };

  public:
    static bool isCousins(TreeNode<int> *root, int x, int y)
    {
        if (nullptr == root)
        {
            return false;
        }

        queue<TreeNode<int> *> q;
        vector<Record *>       records;
        TreeNode<int>         *parent = nullptr;
        int                    level  = 0;

        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            level++;

            for (int i = 0; i < size; ++i)
            {
                TreeNode<int> *node = q.front();
                q.pop();

                if (nullptr != node->getLeft())
                {
                    q.push(node->getLeft());
                    Record *record = new Record();
                    record->data   = node->getLeft()->getData();
                    record->level  = level;
                    record->parent = node;
                    records.push_back(record);
                }

                if (nullptr != node->getRight())
                {
                    q.push(node->getRight());
                    Record *record = new Record();
                    record->data   = node->getRight()->getData();
                    record->level  = level;
                    record->parent = node;
                    records.push_back(record);
                }
            }
        }

        Record *xRecord = nullptr;
        Record *yRecord = nullptr;

        for (Record *record : records)
        {
            // printf("Value: %d, level %d, Parent %d\n", record->data, record->level, record->parent->getData());
            if (record->data == x)
            {
                xRecord = record;
            }

            if (record->data == y)
            {
                yRecord = record;
            }

            if ((nullptr != xRecord) && (nullptr != yRecord))
            {
                if ((xRecord->level == yRecord->level) && (xRecord->parent != yRecord->parent))
                {
                    return true;
                }
                break;
            }
        }

        return false;
    }
};

int main()
{

    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(4);
    tree.insert(1);
    tree.insert(7);
    tree.insert(25);
    tree.insert(15);
    tree.insert(21);
    tree.insert(42);
    tree.insert(22);

    printf("Are cousins: %d\n", Solution::isCousins(tree.root, 1, 21));

    return (0);
}
