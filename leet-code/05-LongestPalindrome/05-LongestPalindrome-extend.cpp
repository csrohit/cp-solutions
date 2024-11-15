#include <iostream>
#include <string>

using namespace std ;

pair<int, int> extend(string s, int i, int j)
{
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        --i;
        ++j;
    }
    return {i + 1, j - 1};
}
string longestPalindrome(string s)
{
    if (s.empty())
    {
        return "";
    }

    pair<int, int> indices{0, 0};
    for (int i = 0; i < s.length(); ++i)
    {
        const auto [l1, r1] = extend(s, i, i);
        if( r1 - l1 > indices.second - indices.first)
        {
            indices = {l1, r1};
        }

        const auto [l2, r2] = extend(s, i, i+1);
        if( r2 - l2 > indices.second - indices.first)
        {
            indices = {l2, r2};
        }
    }

    return  s.substr(indices.first, indices.second - indices.first + 1);
}

int main()
{
    string str = "cbbd";
    cout<<longestPalindrome(str)<<endl;;
    return (0);
}
