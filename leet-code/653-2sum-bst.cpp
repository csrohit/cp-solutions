#include <cstdio>
#include <unordered_set>
#include "./libs/tree/bst.h"


std::unordered_set<int> seen;

bool findTarget(TreeNode<int> *root, int k)
{
    if (nullptr == root)
    {
        return false;
    }

    if (seen.find(k - root->getData()) != seen.end())
    {
        return true;
    }

    seen.insert(root->val);

    return findTarget(root->left, k) || findTarget(root->right, k);
}

int main()
{
    BST<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(6);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);

    printf("Is Target Available: %s\n", findTarget(tree.root, 9) ? "True" : "False");
}
