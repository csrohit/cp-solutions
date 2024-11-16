#include <iostream>
#include <vector>

using namespace std;

int minimumPathSum(vector<vector<int>> grid)
{
    int nRows = grid.size();
    int nCols = grid[0].size();

    vector<vector<int>> dp(nRows, vector<int>(nCols, 0));

    dp[nRows - 1][nCols - 1] = grid[nRows - 1][nCols - 1];

    /* calculate sum for rightmost column */
    for (int idx = nRows - 2; idx >= 0; --idx)
    {
        dp[idx][nCols - 1] = grid[idx][nCols - 1] + dp[idx + 1][nCols - 1];
    }

    /* calculate sum for bottom row */
    for (int idx = nCols - 2; idx >= 0; --idx)
    {
        dp[nRows - 1][idx] = grid[nRows - 1][idx] + dp[nRows - 1][idx + 1];
    }

    for (int idx = nRows - 2; idx >= 0; --idx)
    {

        for (int jdx = nCols - 2; jdx >= 0; --jdx)
        {
                dp[idx][jdx] = grid[idx][jdx] + min(dp[idx + 1][jdx], dp[idx][jdx + 1]);
        }
    }

    return dp[0][0];
}

int main()
{
    vector<vector<int>> grid = {{1,2,3},{4,5,6}};
    cout << "Minimum path sum: " << minimumPathSum(grid) << endl;
    return (0);
}
// 1 2 3
// 4 5 6
