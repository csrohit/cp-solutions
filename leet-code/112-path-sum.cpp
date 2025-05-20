#include "./libs/tree/bst.h"

bool hasPathSum(TreeNode<int> *root, int targetSum)
{
    if ((nullptr == root) && (0 == targetSum))
    {
        return true;
    }

    if ((nullptr == root) || (0 == targetSum))
    {
        return false;
    }

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

int main()
{

    BST<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(8);
    tree.insert(11);
    tree.insert(7);
    // tree.insert(2);
    // tree.insert(13);
    // tree.insert(4);
    // tree.insert(1);

    printf("Has path sum %s\n", hasPathSum(tree.root, 21) ? "True" : "False");

    return 0;
}
