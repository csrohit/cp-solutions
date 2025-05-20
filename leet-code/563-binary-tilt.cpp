#include <cstdio>
#include <queue>
#include "libs/tree/bst.h"

using std::queue;
using std::vector;

using std::max;

class Solution
{
  public:
    int binaryTilt(TreeNode<int> *root)
    {
        int tilt = 0;
        dfs(root, tilt);
        return tilt;
    }

    int dfs(TreeNode<int> *node, int &tilt)
    {
        if (nullptr == node)
        {
            return 0;
        }

        int left  = dfs(node->getLeft(), tilt);
        int right = dfs(node->getRight(), tilt);

        tilt += abs(left - right);
        printf("Node: %d -- Left: %d, Right: %d, Diameter: %d\n", node->getData(), left, right, tilt);
        return (left + right + node->getData());
    }
};

int main()
{

    BinaryTree<int> tree;
    tree.root = new TreeNode(4);
    tree.root->setLeft(new TreeNode(2));
    tree.root->getLeft()->setLeft(new TreeNode(3));
    tree.root->getLeft()->setRight(new TreeNode(5));
    tree.root->setRight(new TreeNode(9));
    tree.root->getRight()->setRight(new TreeNode(7));
    // tree.insert(1);
    // tree.insert(2);
    // tree.insert(3);
    // tree.insert(10);
    // tree.insert(5);
    // tree.insert(20);
    // tree.insert(3);
    // tree.insert(4);
    // tree.insert(1);
    // tree.insert(7);
    // tree.insert(25);
    // tree.insert(15);
    // tree.insert(21);
    // tree.insert(42);
    // tree.insert(22);

    printf("Tilt: %d\n", Solution().binaryTilt(tree.root));

    return (0);
}
