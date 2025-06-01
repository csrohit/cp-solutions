#include <vector>

/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=problem-list-v2&envId=array
 */

using std::vector;

class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        int len = nums.size();
        for (int idx = 0; idx < len; ++idx)
        {
            if (nums[idx] == val)
            {
                int lastIndex = len - 1;
                // Ensure lastIndex is not before idx and within bounds
                while (lastIndex >= idx && nums[lastIndex] == val)
                {
                    lastIndex--;
                    len--;
                }
                if (lastIndex < idx)
                    break; // No more valid elements to swap

                nums[idx] = nums[lastIndex];
                len--;
                idx--; // Recheck the swapped-in value
            }
        }
        return len;
    }
};

int main()
{
    Solution         sol;
    std::vector<int> nums{1, 3, 7, 7, 5, 6};
    int len = sol.removeElement(nums, 7);

    for (int idx = 0; idx < len; ++idx)
    {
        printf("%-4d", nums[idx]);
    }
    printf("\n");
}
