#include <vector>

/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=problem-list-v2&envId=array
 */

using std::vector;

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int uniq = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[uniq++] = nums[i];
            }
        }
        return uniq;
    }

};

int main()
{
    Solution         sol;
    std::vector<int> nums{1, 3, 7, 7,  5, 6};
    constexpr int nUniq = 5;
    sol.removeDuplicates(nums);

    for (int idx = 0; idx < nUniq; ++idx)
    {
        printf("%-4d", nums[idx]);
    }
    printf("\n");
}
