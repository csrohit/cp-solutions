#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool canPartition(vector<int> &nums, int idx, int target, vector<vector<int>> dp)
{
    if (target == 0)
    {
        return true;
    }
    else if (idx == 0)
    {
        return target == nums[0];
    }
    else if (dp[idx][target] != -1)
    {
        return dp[idx][target];
    }
    else
    {
        bool notInclude = canPartition(nums, idx - 1, target, dp);
        bool include    = false;

        if (target >= nums[idx])
        {
            include = canPartition(nums, idx - 1, target - nums[idx], dp);
        }
        return (dp[idx][target] = notInclude | include);
    }
}

bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (0 != sum % 2)
    {
        return false;
    }

    int target = sum / 2;

    vector<vector<int>> dp(nums.size() , vector<int>(target + 1, -1));

    return canPartition(nums, nums.size() - 1, target, dp);
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << "Can partition: " << canPartition(nums) << endl;
    return (0);
}
