#include <bits/stdc++.h>
using namespace std;

// Function to find the count of Longest Increasing Subsequences (LIS)
int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();

    vector<int> dp(n, 1); // dp[i] stores the length of the LIS ending at arr[i]
    vector<int> ct(n, 1); // ct[i] stores the count of LIS ending at arr[i]

    int maxi = 1; // Initialize the maximum length as 1

    for (int i = 0; i < n; i++)
    {
        for (int prev_index = 0; prev_index < i; prev_index++)
        {
            if (arr[prev_index] < arr[i] && dp[prev_index] + 1 > dp[i])
            {
                dp[i] = dp[prev_index] + 1;
                // Inherit count
                ct[i] = ct[prev_index];
            }
            else if (arr[prev_index] < arr[i] && dp[prev_index] + 1 == dp[i])
            {
                // Increase the count
                ct[i] = ct[i] + ct[prev_index];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int numberOfLIS = 0;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
        {
            numberOfLIS += ct[i];
        }
    }

    return numberOfLIS;
}

int main()
{
    vector<int> arr = {1, 5, 4, 3, 2, 6, 7, 2};

    cout << "The count of Longest Increasing Subsequences (LIS) is " << findNumberOfLIS(arr) << endl;

    return 0;
}