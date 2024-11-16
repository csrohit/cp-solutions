#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int> &nums)
{
    int result = 0;

    int left = 0, right = 0;

    while (right < nums.size() - 1)
    {
        int maxJump = 0;
        for(int idx = left; idx <= right; ++idx)
        {
            maxJump = max(maxJump, idx + nums[idx]);
        }
        left = right;
        right = maxJump;
        result++;
    }

    return result;
}

int main()
{
    vector<int> nums{2, 3, 4, 1, 4, 1, 1, 1, 3};
    std::cout << "Max Jumps: " << jump(nums) << endl;
    return (0);
}
