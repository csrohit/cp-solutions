#include <cstdio>
#include <vector>

using std::vector;

struct TreeNode
{
    int       val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};


class Solution
{
    TreeNode* bstFromPreorder(vector<int>& nums)
    {
        return dfs(nums, 0, std::numeric_limits<int>::max());    
    };

    TreeNode* dfs(vector<int>& nums, int idx, int bound)
    {
        if ((0 == nums.size()) && (nums[idx] > bound))
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(nums[index++]);
    };
};

int main()
{

    return 0;
}
