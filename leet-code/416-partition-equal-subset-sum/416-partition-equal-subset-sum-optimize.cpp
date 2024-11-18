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

    sum = sum / 2;

    vector<bool> dp(sum + 1, false);

    dp[0] = true;

    for (int num: nums)
    {
        for (int target = sum; target >= num; --target)
        {
            bool notInclude = dp[target];
            bool include = dp[target - num];
            dp[target] = include | notInclude;
        }
    }

    return dp[sum];
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << "Can partition: " << canPartition(nums) << endl;
    return (0);
}
