#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>> obstacleGrid)
{
    if (obstacleGrid[i][j] == 1)
        return 0;
    if (i == m && j == n)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = 0, right = 0;
    if (i < m)
        down = solve(i + 1, j, m, n, dp, obstacleGrid);
    if (j < n)
        right = solve(i, j + 1, m, n, dp, obstacleGrid);
    return dp[i][j] = down + right;
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(0, 0, m - 1, n - 1, dp, obstacleGrid);
}
int mazeObstaclesUtil(int n, int m, vector<vector<int>> &maze, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Base conditions
            if (i > 0 && j > 0 && maze[i][j] == -1)
            {
                dp[i][j] = 0; // If there's an obstacle at (i, j), no paths can pass through it
                continue;
            }
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1; // If we are at the starting point, there is one path to it
                continue;
            }

            int up = 0;
            int left = 0;

            // Check if we can move up and left (if not at the edge of the maze)
            if (i > 0)
                up = dp[i - 1][j]; // Number of paths from above
            if (j > 0)
                left = dp[i][j - 1]; // Number of paths from the left

            // Total number of paths to reach (i, j) is the sum of paths from above and left
            dp[i][j] = up + left;
        }
    }

    // The final result is stored in dp[n-1][m-1], which represents the destination
    return dp[n - 1][m - 1];
}
// Main function to count paths with obstacles in a maze
int mazeObstacles(int n, int m, vector<vector<int>> &maze)
{
    vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
    return mazeObstaclesUtil(n, m, maze, dp);      // Start from the top-left corner (0, 0)
}
// Function to count the number of paths from the top-left corner (0, 0) to the bottom-right corner (n-1, m-1)
int mazeObstacles(int n, int m, vector<vector<int>> &maze)
{
    vector<int> prev(m, 0); // Initialize a vector to store the previous row's path counts

    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0); // Initialize a temporary vector for the current row
        for (int j = 0; j < m; j++)
        {
            // Base conditions
            if (i > 0 && j > 0 && maze[i][j] == -1)
            {
                temp[j] = 0; // If there's an obstacle at (i, j), no paths can pass through it
                continue;
            }
            if (i == 0 && j == 0)
            {
                temp[j] = 1; // If we are at the starting point, there is one path to it
                continue;
            }

            int up = 0;
            int left = 0;

            // Check if we can move up and left (if not at the edge of the maze)
            if (i > 0)
                up = prev[j]; // Number of paths from above (previous row)
            if (j > 0)
                left = temp[j - 1]; // Number of paths from the left (current row)

            // Total number of paths to reach (i, j) is the sum of paths from above and left
            temp[j] = up + left;
        }
        prev = temp; // Update the previous row with the current row
    }
    // The final result is stored in prev[m-1], which represents the destination in the last row
    return prev[m - 1];
}
int main()
{
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << uniquePathsWithObstacles(obstacleGrid);
}