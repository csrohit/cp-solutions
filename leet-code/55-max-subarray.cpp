#include <iostream>
#include <vector>

using namespace std;

int maxSubarray(vector<int> &nums)
{
    int sum         = INT_MIN;
    int subArraySum = 0;

    for (int num : nums)
    {
        subArraySum += num;
        sum = max(sum, subArraySum);
        if(subArraySum < 0)
        {
            subArraySum = 0;
        }
    }

    return sum;
}

int main()
{
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    cout<< "Max Sum: " << maxSubarray(nums) << endl;
    return (0);
}
