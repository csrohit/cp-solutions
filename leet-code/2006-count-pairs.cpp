#include <cstdio>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;

int countPairs(vector<int>& nums, int k)
{
    int count = 0;

    unordered_map<int, int> freq;

    for (const int n: nums)
    {
        printf("Frequency of %d is %d\n", n, freq[n]);
    }

    return count;
}



int main()
{
    vector<int> nums = {1, 2, 2, 1};

    printf("NUmber of pairs: %d\n", countPairs(nums, 1));


    return 0;
}
