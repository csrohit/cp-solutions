#include <cstdio>
#include <vector>

using std::vector;

struct TreeNode
{
    int              val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {};
};

class Solution
{
  public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode *dfs(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int maxVal = -1;
        int maxIdx = 0;

        for (int i = left; i <= right; ++i)
        {
            if (maxVal < nums[i])
            {
                maxVal = nums[i];
                maxIdx = i;
            }
        }

        TreeNode* node = new TreeNode(maxVal);
        node->left = dfs(nums, left, maxIdx-1);
        node->right = dfs(nums, maxIdx + 1, right);

        return node;

    }
};

int main()
{

    return 0;
}
