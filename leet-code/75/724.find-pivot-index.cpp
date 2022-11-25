/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */
#include<vector>
#include<iostream>

using namespace std;


// @lc code=start

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sums{0};
        int total=0;
        for(int i : nums){
            sums.push_back(sums.back() + i);
        }
        total = sums.back();

        for(int i=0; i< sums.size(); i++){
            if(sums[i] == total - sums[i+1]){
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end


int main(){

    Solution sol;
    vector<int> nums {1,3,7,6,5,6};
    cout << sol.pivotIndex(nums)<< endl;
    return 0;
}