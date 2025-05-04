#include <bits/stdc++.h>
using namespace std;
int countWaysUtil(int m, int n, vector<vector<int>> &dp)
{
    // Loop through the grid using two nested loops
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Base condition: If we are at the top-left cell (0, 0), there is one way.
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue; // Skip the rest of the loop and continue with the next iteration.
            }
            // Initialize variables to store the number of ways from the cell above (up) and left (left).
            int up = 0;
            int left = 0;
            // If we are not at the first row (i > 0), update 'up' with the value from the cell above.
            if (i > 0)
                up = dp[i - 1][j];
            // If we are not at the first column (j > 0), update 'left' with the value from the cell to the left.
            if (j > 0)
                left = dp[i][j - 1];
            // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            dp[i][j] = up + left;
        }
    }
    // The result is stored in the bottom-right cell (m-1, n-1).
    return dp[m - 1][n - 1];
}
// Function to count the number of ways to reach the bottom-right cell (m-1, n-1)
// from the top-left cell (0, 0) in a grid of size m x n
int countWays_Tab(int m, int n)
{
    // Create a memoization table (dp) to store the results of subproblems.
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // Call the utility function with the grid size and the memoization table.
    return countWaysUtil(m, n, dp);
}
int countWays_Space_Opt(int m, int n)
{
    // Create a vector to represent the previous row of the grid.
    vector<int> prev(n, 0);
    // Iterate through the rows of the grid.
    for (int i = 0; i < m; i++)
    {
        // Create a temporary vector to represent the current row.
        vector<int> temp(n, 0);
        // Iterate through the columns of the grid.
        for (int j = 0; j < n; j++)
        {
            // Base case: If we are at the top-left cell (0, 0), there is one way.
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }
            // Initialize variables to store the number of ways from the cell above (up) and left (left).
            int up = 0;
            int left = 0;
            // If we are not at the first row (i > 0), update 'up' with the value from the previous row.
            if (i > 0)
                up = prev[j];
            // If we are not at the first column (j > 0), update 'left' with the value from the current row.
            if (j > 0)
                left = temp[j - 1];
            // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            temp[j] = up + left;
        }
        // Update the previous row with the values calculated for the current row.
        prev = temp;
    }
    // The result is stored in the last cell of the previous row (n-1).
    return prev[n - 1];
}
int solve(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return 1;
    if (dp[m][n] != -1)
        return dp[m][n];
    int top = 0, left = 0;
    if (m > 0)
        top = solve(m - 1, n, dp);
    if (n > 0)
        left = solve(m, n - 1, dp);
    return dp[m][n] = top + left;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m - 1, n - 1, dp);
}
int main()
{
    int m = 3, n = 7;
    cout << uniquePaths(m, n);
}