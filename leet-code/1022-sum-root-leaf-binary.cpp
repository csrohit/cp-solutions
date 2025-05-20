#include <cstdio>
#include <queue>
#include "libs/tree/bst.h"

using std::queue;
using std::vector;

using std::max;

class Solution
{
  public:
    int sumRootLeaf(TreeNode<int> *root)
    {
        int s = 0;
        return dfs(root, s);
    }

    int dfs(TreeNode<int> *node, int previousSum)
    {
        if (nullptr == node)
        {
            return 0;
        }

        previousSum = previousSum << 1;
        previousSum = previousSum | node->getData();

        if ((nullptr == node->getLeft()) && nullptr == (node->getRight()))
        {
            return previousSum;
        }


        int left  = dfs(node->getLeft(), previousSum);
        int right = dfs(node->getRight(), previousSum);

        printf("Node: %d -- Left: %d, Right: %d, sum: %d\n", node->getData(), left, right, previousSum);
        return (left + right);
    }
};

int main()
{

    BinaryTree<int> tree;
    tree.root = new TreeNode(1);
    tree.root->setLeft(new TreeNode(0));
    tree.root->getLeft()->setLeft(new TreeNode(0));
    tree.root->getLeft()->setRight(new TreeNode(1));
    tree.root->setRight(new TreeNode(1));
    tree.root->getRight()->setRight(new TreeNode(1));
    tree.root->getRight()->setLeft(new TreeNode(0));

    printf("Tilt: %d\n", Solution().sumRootLeaf(tree.root));

    return (0);
}
