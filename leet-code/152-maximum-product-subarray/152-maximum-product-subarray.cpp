#include <iostream>
#include <vector>

using namespace std;

int maximumProduct(vector<int> nums)
{
    int ans = 0;

    int maxProduct = 1;
    int minProduct = 1;

    for (int num : nums)
    {
        if (num == 0)
        {
            maxProduct = 1;
            minProduct = 1;
            continue;
        }

        int tmp = maxProduct;
        if (num < 0)
        {
            swap(maxProduct, minProduct);
        }

        maxProduct = max(num, maxProduct * num);
        minProduct = min(num, minProduct * num);

        ans = max(ans, maxProduct);
    }

    return ans;
}

int main()
{
    vector<int> nums = {-2, -9, 0, 1};
    cout << "Max Product: " << maximumProduct(nums) << endl;
    return (0);
}
