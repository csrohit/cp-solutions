#include <cstdio>
#include <vector>
#include <iostream>
#include "./libs/tree/bst.h"






int main()
{
    BinaryTree<int> tree;
    tree.root = new TreeNode(5);
    tree.root->setLeft(new TreeNode(4));
    tree.root->setRight(new TreeNode(8));
    tree.root->getLeft()->setLeft(new TreeNode(11));
    tree.root->getLeft()->getLeft()->setLeft(new TreeNode(7));
    tree.root->getLeft()->getLeft()->setLeft(new TreeNode(2));
    //
    // tree.root->getRight()->setLeft(new TreeNode(13));
    // tree.root->getRight()->setRight(new TreeNode(4));
    // tree.root->getRight()->getRight()->setRight(new TreeNode(1));
    // tree.root->getRight()->getRight()->setLeft(new TreeNode(5));

    printf("Constructed tree: ");
    std::vector<int> result;
    tree.getInorder(result);

    for(const int i: result)
    {
        printf("%-3d", i);
    }

    std::cout << std::endl;

    return 0;
}
