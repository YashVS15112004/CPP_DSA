#include <bits/stdc++.h>
using namespace std;
int f(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{

    // base condition
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    // partioning loop
    for (int k = i; k <= j - 1; k++)
    {

        int ans = f(arr, i, k, dp) + f(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];

        mini = min(mini, ans);
    }

    return mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    int i = 1;
    int j = N - 1;
    return f(arr, i, j, dp);
}
// Function to find the minimum number of operations for matrix multiplication
int matrixMultiplication_TAB(vector<int> &arr, int N)
{
    // Create a DP table to store the minimum number of operations
    vector<vector<int>> dp(N, vector<int>(N,0));
    // Loop for the length of the chain
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {

                int ans = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, ans);
            }
            dp[i][j] = mini;
        }
    }
    // The result is stored in dp[1][N-1]
    return dp[1][N - 1];
}
int main()
{

    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();
    cout << "The minimum number of operations is " << matrixMultiplication(arr, n) << endl;
    cout << "The minimum number of operations is " << matrixMultiplication_TAB(arr, n) << endl;
    return 0;
}