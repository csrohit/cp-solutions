#include <iostream>
#include <numeric>
#include <vector>

using namespace std;


bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (0 != sum % 2)
    {
        return false;
    }

    int k = sum / 2;

    vector<vector<bool>> dp(nums.size(), vector<bool>(k + 1, -1));

    for (int idx = 0; idx < nums.size(); ++idx)
    {
        dp[idx][0] = true;
    }
    dp[0][nums[0]] = true;

    for (int idx = 1; idx < nums.size(); ++idx)
    {
        for (int target = 1; target <= k; ++target)
        {
            bool notInclude = dp[idx - 1][target];
            bool include    = false;

            if (target >= nums[idx])
            {
                include = dp[idx - 1][target - nums[idx]];
            }
        }
    }

    return dp[nums.size() - 1][k];
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << "Can partition: " << canPartition(nums) << endl;
    return (0);
}
