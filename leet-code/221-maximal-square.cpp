#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    int       ans   = 0;
    const int nRows = matrix.size();
    const int nCols = matrix[0].size();

    /* Add extra row and column with all 0s this prevents separate hadnling of first row and last column */
    vector<vector<int>> dp(nRows + 1, vector<int>(nCols + 1, 0));

    for (int idx = nRows - 1; idx >= 0; --idx)
    {
        for (int jdx = nCols - 1; jdx >= 0; --jdx)
        {
            if ('1' == matrix[idx][jdx])
            {
                dp[idx][jdx] = 1 + min(dp[idx + 1][jdx], min(dp[idx + 1][jdx + 1], dp[idx][jdx + 1]));
                ans          = max(ans, dp[idx][jdx]);
            }
            else
            {
                dp[idx][jdx] = 0;
            }
        }
    }

    return ans * ans;
}

int main()
{

    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};

    cout << "Maximal Square: " << maximalSquare(matrix) << endl;

    return (0);
}
