#include <iostream>
#include <vector>

using namespace std;

int maxSumDivisibleBy3(vector<int> &nums)
{
    vector<int> dp(3, 0);

    for(int num: nums)
    {
        for(const int sum: vector<int>(dp))
        {
            int newSum = sum + num;
            int idx = newSum % 3;
            dp[idx] = max(dp[idx], newSum);
        }
    }

    return dp[0];
}

int main()
{
    vector<int> nums = {3,6,5,1,8};
    cout << "Max sum: " << maxSumDivisibleBy3(nums) << endl;
    return (0);
}

