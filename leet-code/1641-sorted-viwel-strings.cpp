#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int countVowelStrings(int n)
{
    vector<int> dp(5, 1);
    
    for(int i = 1; i < n; ++i)
    {
        for(int j = dp.size() - 2; j >= 0; --j)
        {
            dp[j] += dp[j+1];
        }
    }

    return accumulate(dp.begin(), dp.end(), 0);
}

int main()
{
    cout << "Number of sorted vowel strings: " << countVowelStrings(33) << endl;
    return (0);
}
