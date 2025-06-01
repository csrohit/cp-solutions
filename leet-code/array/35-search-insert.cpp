#include<vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int idx = 0;
        for (;idx < nums.size() && (nums[idx] < target) ; ++idx)
        {
            // printf("Number %d\n", nums[idx]);
        }
        return idx;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums{1, 3, 5, 6};
    printf("Position: %d\n", sol.searchInsert(nums, 7)); 
}
