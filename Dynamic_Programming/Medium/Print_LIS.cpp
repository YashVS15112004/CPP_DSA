#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{

    vector<int> dp(n, 1);
    vector<int> hash(n, 1);

    for (int i = 0; i <= n - 1; i++)
    {

        hash[i] = i; // initializing with current index
        for (int prev_index = 0; prev_index <= i - 1; prev_index++)
        {

            if (arr[prev_index] < arr[i] && 1 + dp[prev_index] > dp[i])
            {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }

    int ans = -1;
    int lastIndex = -1;

    for (int i = 0; i <= n - 1; i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);

    while (hash[lastIndex] != lastIndex)
    { // till not reach the initialization value
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    // reverse the array
    reverse(temp.begin(), temp.end());

    cout << "The subsequence elements are ";

    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;

    return ans;
}

int main()
{

    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};

    int n = sizeof(arr) / sizeof(arr[0]);
    longestIncreasingSubsequence(arr, n);
    return 0;
}