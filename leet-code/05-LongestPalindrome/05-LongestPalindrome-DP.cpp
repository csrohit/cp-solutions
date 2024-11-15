#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s)
{
    if (s.empty())
    {
        return "";
    }

    pair<int, int> indices{0, 0};
    int            ans = 1, len = s.length();

    std::vector<std::vector<bool>> dp(s.length(), std::vector<bool>(s.length(), false));

    dp[0][0] = true;

    for (size_t idx = 1UL; idx < len; ++idx)
    {
        dp[idx][idx] = true;
        if (s.at(idx) == s.at(idx - 1))
        {
            dp[idx - 1][idx] = true;
            if (1 == ans)
            {
                indices = {idx - 1, idx};
                ++ans;
            }
        }
    }

    // loop over lengths 3 to n
    for (size_t subStrLen = 3UL; subStrLen <= len; ++subStrLen)
    {
        for (ssize_t startIdx = 0; startIdx < len - subStrLen + 1; ++startIdx)
        {
            int endIdx = subStrLen + startIdx - 1;
            if (dp[startIdx + 1][endIdx - 1] && s[startIdx] == s[endIdx])
            {
                dp[startIdx][endIdx] = true;
                if (subStrLen > ans)
                {
                    indices = {startIdx, endIdx};
                    ans     = subStrLen;
                }
            }
        }
    }

    return s.substr(indices.first, ans);
}

int main()
{
    string str = "cbabc";
    cout << longestPalindrome(str) << endl;
    ;
    return (0);
}
