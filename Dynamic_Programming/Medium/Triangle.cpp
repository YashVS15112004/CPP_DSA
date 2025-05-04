#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, int n, vector<vector<int>> &dp, vector<vector<int>> &triangle)
{
    if (i == n)
        return triangle[i][j];
    if (dp[i][j] != 1e9)
        return dp[i][j];
    int dn = 1e9, dr = 1e9;
    if (i < n)
        dn = solve(i + 1, j, n, dp, triangle) + triangle[i][j];
    if (i < n && j < triangle[i + 1].size() - 1)
        dr = solve(i + 1, j + 1, n, dp, triangle) + triangle[i][j];
    return dp[i][j] = min(dn, dr);
}
int minimumTotal_mem(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    return solve(0, 0, n - 1, dp, triangle);
}
int minimumTotal_tab(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // Initialize the bottom row of dp with the values from the triangle
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }
    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            // Store the minimum of the two possible paths in dp
            dp[i][j] = min(down, diagonal);
        }
    }
    // The top-left cell of dp now contains the minimum path sum
    return dp[0][0];
}
int minimumPathSum_opt(vector<vector<int>> &triangle) {
    int n = triangle.size();
    // Create two arrays to store the current and previous row values
    vector<int> front(n, 0); // Represents the previous row
    vector<int> cur(n, 0);   // Represents the current row
    
    // Initialize the front array with values from the last row of the triangle
    for (int j = 0; j < n; j++) {
        front[j] = triangle[n - 1][j];
    }
    
    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];
            
            // Store the minimum of the two possible paths in the current row
            cur[j] = min(down, diagonal);
        }
        // Update the front array with the values from the current row
        front = cur;
    }
    
    // The front array now contains the minimum path sum from the top to the bottom of the triangle
    return front[0];
}
int main()
{
    vector<vector<int>> triangle = {{-1}, {-2, -3}};
    cout << minimumTotal_mem(triangle);
}