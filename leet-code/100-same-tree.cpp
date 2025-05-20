#include <cstdio>
#include <queue>
#include "libs/tree/bst.h"

using std::queue;
using std::vector;

using std::max;

class Solution
{
  public:
    bool isSameTreeRecurse(TreeNode<int> *rootA, TreeNode<int> *rootB)
    {
        if ((nullptr == rootA) && (nullptr == rootB))
        {
            return true;
        }

        if ((nullptr == rootA) || (nullptr == rootB))
        {
            return false;
        }

        return (rootA->getData() == rootB->getData()) && isSameTreeRecurse(rootA->getLeft(), rootB->getLeft()) && isSameTreeRecurse(rootA->getRight(), rootB->getRight());
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

    printf("Is same tree %s\n", Solution().isSameTreeRecurse(tree.root, tree.root) ? "True" : "False");

    return (0);
}
