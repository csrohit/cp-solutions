#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int nRows, int nCols)
{
    int ans = 0;

    vector<vector<int> > dp(nRows, vector<int>(nCols, 0));

    for(int idx = 0; idx < nRows; ++idx)
    {
        dp[idx][nCols - 1] = 1;
    }

    for(int idx = 0; idx < nCols; ++idx)
    {
        dp[nRows - 1][idx] = 1;
    }

    for(int idx = nRows - 2; idx >= 0; --idx)
    {

        for(int jdx = nCols - 2; jdx >= 0; --jdx)
        {
            dp[idx][jdx] = dp[idx + 1][jdx] + dp[idx][jdx + 1];
        }
    }

    return dp[0][0];
}

int main()
{
    cout << "Unique Paths: " << uniquePaths(3, 7) << endl;
    return (0);
}
