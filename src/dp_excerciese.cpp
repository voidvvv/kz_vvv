#include "dp_excercise.h"

int uniquePaths(int m, int n)
{
    int dp[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
            {
                dp[i][j] += dp[i - 1][j]; // From the top
            }
            if (j > 0)
            {
                dp[i][j] += dp[i][j - 1]; // From the left
            }
        }
    }
    return dp[m - 1][n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    const int OBSTACLE = 1;
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == OBSTACLE)
            {
                dp[i][j] = 0; // If there's an obstacle, no paths through this cell
            }
            else
            {
                if (i > 0)
                {
                    dp[i][j] += dp[i - 1][j]; // From the top
                }
                if (j > 0)
                {
                    dp[i][j] += dp[i][j - 1]; // From the left
                }
            }
        }
    }

    return dp[m - 1][n - 1];
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && j > 0)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]); // Take the minimum from top or left
            }
            else if (i > 0)
            {
                dp[i][j] = dp[i - 1][j]; // Only can come from the top
            }
            else if (j > 0)
            {
                dp[i][j] = dp[i][j - 1]; // Only can come from the left
            }
            else
            {
                dp[i][j] = 0; // Starting point
            }
            dp[i][j] += grid[i][j]; // Add the current cell's value
        }
    }
    return dp[m - 1][n - 1];
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][0] = triangle[0][0]; // Start with the top of the triangle
    int last = 0;
    int cur = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                dp[cur][j] = dp[last][j] + triangle[i][j]; // Only can come from the top
            }
            else if (j == i)
            {
                dp[cur][j] = dp[last][j - 1] + triangle[i][j]; // Only can come from the left diagonal
            }
            else
            {
                dp[cur][j] = min(dp[last][j - 1], dp[last][j]) + triangle[i][j]; // Can come from the left diagonal
            }
        }
        int tmp = last;
        last = cur;
        cur = tmp; // Swap last and cur
    }

    int minTotal = dp[last][0];
    for (int j = 1; j < n; j++)
    {
        minTotal = min(minTotal, dp[last][j]); // Find the minimum path sum in the last row
    }
    return minTotal;
}

void printVector(const vector<int> &v)

{
    for (const auto &elem : v)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> dp = vector<vector<int>>(2, vector<int>(n, 0));
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        dp[0][i] = matrix[0][i]; // Initialize the first row
        ans = min(ans, dp[0][i]); // Find the minimum in the first row
    }
    int last = 0;
    int cur = 1;
    for (int i = 1; i < n; i++) {
        int minVal = INT_MAX;
        for (int j = 0; j < n; j++) {
            dp[cur][j] = dp[last][j] + matrix[i][j]; // From the top
            if (j > 0) {
                dp[cur][j] = min(dp[cur][j], dp[last][j - 1] + matrix[i][j]); // From the left diagonal
            }
            if (j < n - 1) {
                dp[cur][j] = min(dp[cur][j], dp[last][j + 1] + matrix[i][j]); // From the right diagonal
            }
            minVal = min(minVal, dp[cur][j]);
            
        }
        ans = minVal;
        int tmp = last;
        last = cur;
        cur = tmp; // Swap last and cur
    }
    return ans; // Return the minimum value from the last row
}