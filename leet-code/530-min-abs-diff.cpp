#include <cstdio>
#include <queue>
#include "libs/tree/bst.h"

using std::queue;
using std::vector;

int minDifference(BST<int>& tree)
{
    vector<int> values;
    tree.getInorder(values);

    int minDiff = INT_MAX;

    for (int i = 1; i < values.size(); ++i)
    {
        minDiff = std::min(minDiff, values.at(i) - values.at(i-1));
    }
    return minDiff;
}


int main()
{

    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(49);
    tree.insert(1);
    tree.insert(7);
    tree.insert(25);
    tree.insert(15);
    tree.insert(23);
    tree.insert(42);
    tree.insert(28);

    printf("Min difference: %d\n", minDifference(tree));

    return (0);
}

