#include <cstdio>
#include <queue>
#include "libs/tree/bst.h"

using std::pair;
using std::queue;
using std::stack;
using std::vector;

using std::max;

class SolutionIterative
{
  public:
    bool isSubTree(TreeNode<int> *root, TreeNode<int> *subRoot)
    {
        if (nullptr == subRoot)
        {
            return true;
        }

        if (nullptr == root)
        {
            return false;
        }

        stack<TreeNode<int> *> st;

        st.push(root);

        while (!st.empty())
        {
            TreeNode<int> *node = st.top();
            st.pop();

            if ((node->getData() == subRoot->getData()) && isSameTree(node, subRoot))
            {
                return true;
            }

            if (nullptr != node->getLeft())
            {
                st.push(node->getLeft());
            }

            if (nullptr != node->getRight())
            {
                st.push(node->getRight());
            }
        }
        return false;
    }

    bool isSameTree(TreeNode<int> *rootA, TreeNode<int> *rootB)
    {
        stack<pair<TreeNode<int> *, TreeNode<int> *>> st;
        st.push({rootA, rootB});

        while (!st.empty())
        {
            auto [node1, node2] = st.top();
            st.pop();

            if ((nullptr == node1) && (nullptr == node2))
            {
                continue;
            }

            if ((nullptr == node1) || (nullptr == node2) || (node1->getData() != node2->getData()))
            {
                return false;
            }

            st.push({node1->getLeft(), node2->getLeft()});
            st.push({node1->getRight(), node2->getRight()});
        }

        return false;
    }
};

class Solution
{
  public:
    bool isSubTree(TreeNode<int> *root, TreeNode<int> *subRoot)
    {
        if (nullptr == subRoot)
        {
            return true;
        }

        if (nullptr == root)
        {
            return false;
        }

        return isSameTree(root, subRoot) || isSubTree(root->getLeft(), subRoot) || isSubTree(root->getRight(), subRoot);
    }

    bool isSameTree(TreeNode<int> *rootA, TreeNode<int> *rootB)
    {
        if ((nullptr == rootA) && (nullptr == rootB))
        {
            return true;
        }

        if ((nullptr == rootA) || (nullptr == rootB))
        {
            return false;
        }

        return (rootA->getData() == rootB->getData()) && isSameTree(rootA->getLeft(), rootB->getLeft()) && isSameTree(rootA->getRight(), rootB->getRight());
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

    BST<int> subTree;
    subTree.insert(3);
    // subTree.insert(1);
    subTree.insert(4);

    printf("isSubTree: %s\n", SolutionIterative().isSubTree(tree.root, subTree.root) ? "True" : "False");

    return (0);
}
