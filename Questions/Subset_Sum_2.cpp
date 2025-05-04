#include<bits/stdc++.h>
using namespace std;
void fun(vector < int > & nums, int index, vector < int > ds, set < vector < int >> & res) {
      if (index == nums.size()) {
        sort(ds.begin(), ds.end());
        res.insert(ds);
        return;
      }
      ds.push_back(nums[index]);
      fun(nums, index + 1, ds, res);
      ds.pop_back();
      fun(nums, index + 1, ds, res);
    }
  vector<vector<int>> SubsetSum2(vector<int> & nums) {
    vector<vector<int>> ans;
    set<vector<int>> res;
    vector < int > ds;
    fun(nums, 0, ds, res);
    for (auto it = res.begin(); it != res.end(); it++) {
      ans.push_back( * it);
    }
    return ans;
  }
int main()
{
    vector<int> arr = {1,2,2};
    vector<vector<int>> ans = SubsetSum2(arr);
    for(int i=0;i<ans.size();i++)
    {
        for(auto it:ans[i])
        {
            cout<<it<<" ";
        }
    cout<<endl;
    }
    return 0;
}