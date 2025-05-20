#include <iostream>
#include <vector>

using namespace std;

int maxSumAfterPartitioning(vector<int> &nums, int k)
{
    int n = nums.size();

    vector<int> dp(n, 0);
    dp[n - 1] = nums.at(n - 1);

    for (int start = n - 2; start >= 0; --start)
    {
        int currMax = INT_MIN;
        for (int idx = start; idx < min(n, start + k); ++idx)
        {
            currMax   = max(currMax, nums[idx]);
            dp[start] = max(dp[start], currMax * (idx - start + 1) + dp[idx + 1]);
        }
    }

    return dp[0];
}

int main()
{
    vector<int> nums = {1, 15, 7, 9, 2, 5, 10};
    cout << "Max sum: " << maxSumAfterPartitioning(nums, 3) << endl;
    return (0);
}
