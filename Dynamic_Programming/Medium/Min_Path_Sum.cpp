#include <bits/stdc++.h>
using namespace std;
int solve(int n, int m, vector<vector<int>> &dp, vector<vector<int>> grid)
{
    if (n == 0 && m == 0)
        return grid[0][0];
    if (dp[n][m] != -1)
        return dp[n][m];
    int top = 201, left = 201;
    if (m > 0)
        left = solve(n, m - 1, dp, grid) + grid[n][m];
    if (n > 0)
        top = solve(n - 1, m, dp, grid) + grid[n][m];
    return dp[n][m] = min(top, left);
}
int minPathSum_Mem(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, dp, grid);
}
int minPathSum_tab(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else
            {
                int down = 1e9, right = 1e9;
                if (j > 0)
                    right = dp[i][j - 1] + grid[i][j];
                if (i > 0)
                    down = dp[i - 1][j] + grid[i][j];
                dp[i][j] = min(right, down);
            }
        }
    }
    return dp[n - 1][m - 1];
}
int minSumPath(int n, int m, vector<vector<int>> &matrix) {
    vector<int> prev(m, 0); // Initialize a vector to store the previous row's minimum path sums
    for (int i = 0; i < n; i++) {
        vector<int> temp(m, 0); // Initialize a temporary vector for the current row
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                temp[j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else {
                // Calculate the minimum path sum considering moving up and moving left
                int up = matrix[i][j];
                if (i > 0)
                    up += prev[j]; // Include the minimum path sum from above (previous row)
                else
                    up += 1e9; // A large value if moving up is not possible (out of bounds)

                int left = matrix[i][j];
                if (j > 0)
                    left += temp[j - 1]; // Include the minimum path sum from the left (current row)
                else
                    left += 1e9; // A large value if moving left is not possible (out of bounds)

                // Store the minimum path sum in temp[j]
                temp[j] = min(up, left);
            }
        }
        prev = temp; // Update the previous row with the current row
    }
    // The final result is stored in prev[m-1], which represents the destination in the last column
    return prev[m - 1];
}
int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum_tab(grid);
}