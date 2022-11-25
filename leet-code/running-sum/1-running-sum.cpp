#include<vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // vector<int? running_sum(numss.size());
     for(int i=1; i<nums.size(); i++){
         nums[i] += nums[i-1];
     }
        return nums;
    }
};