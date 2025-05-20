#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int pivotIndex(vector<int> &nums)
{
    int rightSum  = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;

    for (int idx = 0; idx < nums.size(); ++idx)
    {
        int num = nums.at(idx);

        /* right sum should contain 1 number less, as to exclude pivot index */
        rightSum -= num;
        if (leftSum == rightSum)
        {
            return idx;
        }
        leftSum += num;
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << "Pivot Index: " << pivotIndex(nums) << endl;
    return (0);
}
