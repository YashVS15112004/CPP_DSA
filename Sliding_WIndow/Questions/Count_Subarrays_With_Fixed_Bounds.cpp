#include <bits/stdc++.h>
using namespace std;
long long countSubarrays(vector<int> &nums, int minK, int maxK)
{
    long count = 0, start = -1, mini = -1, maxi = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < minK || nums[i] > maxK)
            start = i;
        if (nums[i] == maxK)
            maxi = i;
        if (nums[i] == minK)
            mini = i;
        int valid = max(0L, min(mini, maxi) - start);
        count += valid;
    }
    return count;
}
int main()
{
    vector<int> nums = {35054, 398719, 945315, 945315, 820417, 945315, 35054, 945315, 171832, 945315, 35054, 109750, 790964, 441974, 552913};
    int minK = 35054, maxK = 945315;
    cout << countSubarrays(nums, minK, maxK);
}