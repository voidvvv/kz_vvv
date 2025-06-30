#include "dp_excercise.h"

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
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
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = matrix[0][i];  // Initialize the first row
        ans = min(ans, dp[0][i]); // Find the minimum in the first row
    }
    int last = 0;
    int cur = 1;
    for (int i = 1; i < n; i++)
    {
        int minVal = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            dp[cur][j] = dp[last][j] + matrix[i][j]; // From the top
            if (j > 0)
            {
                dp[cur][j] = min(dp[cur][j], dp[last][j - 1] + matrix[i][j]); // From the left diagonal
            }
            if (j < n - 1)
            {
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

int minFallingPathSum2(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> dp(2, vector<int>(n, 0));
    int last = 0;
    int cur = 1;
    int ans = INT_MAX;

    int minIndex = -1;
    int minIndex2 = -1;
    for (int x = 0; x < n; x++)
    {
        dp[0][x] = grid[0][x];    // Initialize the first row
        ans = min(ans, dp[0][x]); // Find the minimum in the first row
        if (minIndex == -1 || dp[0][x] < dp[0][minIndex])
        {
            minIndex2 = minIndex;
            minIndex = x; // Update the minimum index
        }
        else if (minIndex2 == -1 || dp[0][x] < dp[0][minIndex2])
        {
            minIndex2 = x; // Update the second minimum index
        }
    }

    for (int i = 1; i < n; i++)
    {
        int curMin = INT_MAX;
        int curMinIndex = -1;
        int curMinIndex2 = -1;
        for (int j = 0; j < n; j++)
        {
            int cVal = INT_MAX;
            if (j != minIndex)
            {
                cVal = min(cVal, dp[last][minIndex] + grid[i][j]); // From the left diagonal
            }
            else if (j != minIndex2)
            {
                cVal = min(cVal, dp[last][minIndex2] + grid[i][j]); // From the right diagonal
            }
            dp[cur][j] = cVal; // Update the current cell
            if (curMinIndex == -1 || cVal < dp[cur][curMinIndex])
            {
                curMinIndex2 = curMinIndex;
                curMinIndex = j; // Update the current minimum index
            }
            else if (curMinIndex2 == -1 || cVal < dp[cur][curMinIndex2])
            {
                curMinIndex2 = j; // Update the second current minimum index
            }

            curMin = min(curMin, dp[cur][j]); // Find the minimum in the current row
        }
        minIndex = curMinIndex;
        minIndex2 = curMinIndex2;
        ans = curMin;
        int tmp = last;
        last = cur;
        cur = tmp; // Swap last and cur
    }

    return ans;
}


int dfs(vector<int> &locations, int cur, int finish, int fuel, vector<vector<int>> &cache);
int countRoutes(vector<int> &locations, int start, int finish, int fuel)
{
    int n = locations.size();
    vector<vector<int>> cache(n, vector<int>(fuel + 1, -1));
    int ans = dfs(locations, start, finish, fuel, cache);
    return ans;
}

int dfs(vector<int> &locations, int cur, int finish, int fuel, vector<vector<int>> &cache)
{
    if (cache[cur][fuel] != -1)
    {
        return cache[cur][fuel]; // Return cached result
    }

    if (fuel <= 0 && cur != finish)
    {
        cache[cur][fuel] = 0;
        return 0; // Not enough fuel
    }
    int sum = cur == finish ? 1 : 0; // If we are at the finish location, count this route
    for (int i = 0; i < locations.size(); i++)
    {
        if (i != cur)
        {
            int cost = abs(locations[cur] - locations[i]);
            if (fuel >= cost)
            {
                sum += dfs(locations, i, finish, fuel - cost, cache);
                sum %= 1000000007; // To avoid overflow
            }
        }
    }
    cache[cur][fuel] = sum;
    return sum;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, 0)));
    // bound
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
            {
                for (int m = 0; m < maxMove; m++)
                {
                    dp[i][j][m] = 1;
                }
            }
        }
    }
    return 0;
}

int maximalSquare(vector<vector<char>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int maxSide = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            if (matrix[i - 1][j - 1] == '1')
            {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide * maxSide;
}

// int rob(vector<int> &nums)
// {
//     if (nums.size() == 1) {
//         return nums[0]; // If there's only one house, return its value
//     }
//     int s = nums[0];
//     int ss = max(nums[0], nums[1]); // Initialize the second house value
//     for (int i = 2; i < nums.size(); i++)
//     {
//         int cur = max(ss, s + nums[i]); // Calculate the maximum value for the current house
//         s = ss; // Update the previous house value
//         ss = cur; // Update the current house value
//     }
//     return ss; // Return the maximum value after processing all houses
// }