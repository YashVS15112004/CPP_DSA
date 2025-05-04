#include<bits/stdc++.h>
using namespace std;
vector<int> NGE(vector<int> nums)
{
    int n = nums.size();
    vector < int > nge(n,0);
    stack < int > st;
    for (int i = n-1;i>=0;i--) { //Circular Array -> Traverse twice;Inserting the elements of the array A at the end of A
    while (!st.empty() && st.top() <= nums[i])st.pop();
    if (!st.empty()) nge[i] = st.top();
    else nge[i] = -1;
    st.push(nums[i]);
    }
    return nge;
}
int main()
{
    vector<int> nums = {3,0,0,2,0,4};
    vector<int> ans = NGE(nums);
    for(auto it:ans) cout<<it<<" ";
}