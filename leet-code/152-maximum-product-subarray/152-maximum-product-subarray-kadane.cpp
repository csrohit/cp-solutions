#include <iostream>
#include <vector>

using namespace std;

int maximumProduct(vector<int> nums)
{
    int ans = 0;

    int leftProduct  = 1;
    int rightProduct = 1;
    int len          = nums.size();

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 0)
        {
            leftProduct  = 1;
            rightProduct = 1;
            continue;
        }

        int tmp = leftProduct;

        leftProduct  = leftProduct * nums[i];
        rightProduct = rightProduct * nums[len - i - 1];

        ans = max({ans, leftProduct, rightProduct});
    }

    return ans;
}

int main()
{
    vector<int> nums = {-2, -9, 0, 1};
    cout << "Max Product: " << maximumProduct(nums) << endl;
    return (0);
}
