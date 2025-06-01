#include<iostream>
#include <unordered_map>
#include <vector>

/*
https://leetcode.com/problems/two-sum/description/
*/

std::vector<int> twosum(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> map1;
    std::vector<int> v;

    for(int idx = 0; idx < nums.size(); ++idx)
    {
        const std::unordered_map<int, int>::iterator it = map1.find(target - nums[idx]);
        if(it != map1.end())
        printf("Value of member: %d\n", nums[idx]);
    }

    return std::vector<int>(1, 2);
}

int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 15;

    std::vector<int> res = twosum(nums, target);

    if(2 == res.size())
        printf("Indices: %d %d\n", res[0], res[1]);

    return 0;
}
