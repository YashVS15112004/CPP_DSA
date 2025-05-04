#include<bits/stdc++.h>
using namespace std;
int Max_Subarray(vector<int> &nums)
{
    // KADANE'S ALGO
    int maxs = INT_MIN;
    int sum = 0;
    int n = nums.size();
    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i; // starting index
        sum += nums[i];
        if (sum > maxs) {
            maxs = sum;
            ansStart = start;
            ansEnd = i;
        }
        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }
    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << nums[i] << " ";
    }
    cout << "]\n";
    // To consider the sum of the empty subarray
    // uncomment the following check:
    //if (maxi < 0) maxi = 0;
    return maxs;
}
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<Max_Subarray(nums);
}