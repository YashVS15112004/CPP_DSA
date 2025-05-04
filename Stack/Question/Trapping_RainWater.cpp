#include<bits/stdc++.h>
using namespace std;
int trap_better(vector<int>& height) 
{
    int n = height.size();
    vector<int> l(n,-1);
    vector<int> r(n,-1);
    int temp = height[0];
    for(int i=1;i<n;i++)
    {
        if(temp<=height[i]) 
        {
            l[i] = -1;
            temp = height[i];
        }
        else l[i] = temp;
    }
    temp = height[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(temp<=height[i]) 
        {
            r[i] = -1;
            temp = height[i];
        }
        else r[i] = temp;
    }
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(l[i]<=0 || r[i]<=0) continue;
        else ans += min((r[i]-height[i]),(l[i]-height[i]));
    }
    return ans;
}
int trap(vector < int > & height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;
}
int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height);
}