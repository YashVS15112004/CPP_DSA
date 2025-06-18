#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> divideArray(vector<int> &nums, int k)
{
    int n = nums.size(), i = 0;
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    while (i < n - 2)
    {
        int e1 = nums[i], e2 = nums[i + 1], e3 = nums[i + 2];
        if (e3 - e2 <= k && e3 - e1 <= k && e2 - e1 <= k)
            ans.push_back({e1, e2, e3});
        else
            return {};
        i += 3;
    }
    return ans;
}
int main()
{
    vector<int> nums = {4, 2, 9, 8, 2, 12, 7, 12, 10, 5, 8, 5, 5, 7, 9, 2, 5, 11};
    int k = 14;
    vector<vector<int>> ans = divideArray(nums, k);
    for (auto it : ans)
        cout << it[0] << " " << it[1] << " " << it[2] << endl;
}