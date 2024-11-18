#include <iostream>
#include <vector>

using namespace std;

int maxConsecutiveOnes(vector<int> &nums)
{
    int ans = 0;
    int currMax = 0;

    for(int num: nums)
    {
        if (1 == num)
        {
            currMax++;
        }
        else
        {
            ans = max(ans, currMax);
            currMax=  0;
        }
    }

    return max(ans, currMax);
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1};
    cout << "MAx consecutive ones: " << maxConsecutiveOnes(nums) << endl;
    return (0);
}
