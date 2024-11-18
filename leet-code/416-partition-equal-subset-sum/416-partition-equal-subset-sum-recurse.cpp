#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool canPartition(vector<int> &nums, int idx, int target)
{
    if(target == 0)
    {
        return true;
    }
    else if (idx == 0)
    {
        return target == nums[0];
    }
    else
    {
        bool notInclude = canPartition(nums, idx - 1, target);
        bool include = false;
        if(target >= nums[idx])
        {
            include = canPartition(nums, idx - 1, target - nums[idx]);
        }
        return notInclude | include;
    }
}

bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (0 != sum % 2)
    {
        return false;
    }

    return canPartition(nums, nums.size() - 1, sum/2);
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << "Can partition: " << canPartition(nums) << endl;
    return (0);
}
