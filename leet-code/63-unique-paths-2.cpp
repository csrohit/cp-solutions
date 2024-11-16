#include <iostream>
#include <vector>

using namespace std;

int minimumPathSum(vector<vector<int>> obstacles)
{
    int ans   = 0;
    int nRows = obstacles.size();
    int nCols = obstacles[0].size();

    vector<vector<int>> dp(nRows, vector<int>(nCols, 0));
    bool                hasObstacle = false;

    for (int idx = 0; idx < nRows; ++idx)
    {
        hasObstacle        = hasObstacle | obstacles[idx][nCols - 1];
        dp[idx][nCols - 1] = 1 - hasObstacle;
    }
hasObstacle = false;
    for (int idx = 0; idx < nCols; ++idx)
    {
        hasObstacle        = hasObstacle | obstacles[nRows - 1][idx];
        dp[nRows - 1][idx] = 1 - hasObstacle;
    }

    for (int idx = nRows - 2; idx >= 0; --idx)
    {

        for (int jdx = nCols - 2; jdx >= 0; --jdx)
        {
            if (!obstacles[idx][jdx])
                dp[idx][jdx] = dp[idx + 1][jdx] + dp[idx][jdx + 1];
        }
    }

    return dp[0][0];
}

int main()
{
    vector<vector<int>> obstacleGrid = {{0, 1}, {0, 0}};
    cout << "Unique Paths: " << minimumPathSum(obstacleGrid) << endl;
    return (0);
}
