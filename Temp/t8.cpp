#include <bits/stdc++.h>
using namespace std;
int maximumDifference(vector<int> &nums)
{
    int n = nums.size(), maxe = nums[n - 1], maxd = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (maxe - nums[i] > 0)
            maxd = max(maxd, maxe - nums[i]);
        else
            maxe = nums[i];
    }
    return maxd;
}
int main()
{
    vector<int> nums = {9, 4, 3, 2};
    int result = maximumDifference(nums);
    cout << "Maximum difference: " << result << endl;
    return 0;
}
