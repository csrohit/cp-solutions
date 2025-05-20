#include <cstdio>
#include <queue>
#include "libs/tree/bst.h"

using std::queue;
using std::vector;

using std::max;

class Solution
{
  public:
    int diameter(TreeNode<int> *root)
    {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }

    int dfs(TreeNode<int> *node, int &diameter)
    {
        if (nullptr == node)
        {
            return 0;
        }

        int leftDepth  = dfs(node->getLeft(), diameter);
        int rightDepth = dfs(node->getRight(), diameter);

        diameter = max(diameter, leftDepth + rightDepth);
        printf("Node: %d -- Left: %d, Right: %d, Diameter: %d\n", node->getData(), leftDepth, rightDepth, diameter);
        return 1 + max(leftDepth, rightDepth);
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

    printf("Diameter: %d\n", Solution().diameter(tree.root));

    return (0);
}
