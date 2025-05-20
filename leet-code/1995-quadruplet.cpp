
#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    int countQuadruplets(vector<int> &nums)
    {
        int                     n     = nums.size();
        int                     count = 0;
        for (int c = n - 2; c >= 2; --c)
        {
            unordered_map<int, int> freq;

            printf("\nFor C => %d\n", nums[c]);
            for (int d = c + 1; d < n; ++d)
            {
                freq[abs(nums[d] - nums[c])]++;
            }

            for (const pair<int, int> p: freq)
            {
                printf("%3d -> %3d\n", p.first, p.second);
            }

            for (int a = 0; a < c; ++a)
            {
                for (int b = a + 1; b < c; ++b)
                {
                    int sum = nums[a] + nums[b];
                    if (freq.find(sum) != freq.end())
                    {
                        count+= freq[sum];
                    }
                }
            }
            printf("Count => %d\n", count);
        }
        return count;
    }
};

int main()
{
    Solution    solution;
    // vector<int> nums = {1, 1, 1, 3, 5}; // Example input
    vector<int> nums = {9, 6, 8, 23, 39, 23}; // Example input
    cout << "Count of special quadruplets: " << solution.countQuadruplets(nums) << endl;
    return 0;
}
