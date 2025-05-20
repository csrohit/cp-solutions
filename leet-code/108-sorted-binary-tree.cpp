#include <cstdio>
#include <queue>
#include <vector>
#include "libs/tree/bst.h"

using std::vector;

class Solution
{
  public:
    TreeNode<int> *sortedArrayToBST(vector<int> &nums)
    {
        printf("Numsize %lu\n", nums.size());
        return getTree(nums, 0, nums.size() - 1);
    }

    TreeNode<int> *getTree(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int            mid  = left + (right - left) / 2;
        TreeNode<int> *root = new TreeNode(nums[mid]);

        printf("Root Node value: %d -> Left %d, right %d, middle %d\n", root->getData(), left, right, mid);

        // printf("Reading left tree for %d\n", root->getData());
        root->setLeft(getTree(nums, left, mid - 1));
        // printf("Reading Right tree for %d\n", root->getData());
        root->setRight(getTree(nums, mid + 1, right));

        return root;
    }
};

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    BST<int> tree;
    tree.root = Solution().sortedArrayToBST(nums);

    vector<int> result;
    tree.getInorder(result);

    for(int a : result)
    {
        printf("%-4d", a);
    }
    printf("\n");
    return (0);
}
