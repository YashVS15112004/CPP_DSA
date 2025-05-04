#include<bits/stdc++.h>
using namespace std;
vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans(nums.size());
    int p=0,n=1;
    for(auto it:nums)
    {
        if(it>0)
        {
            ans[p] = it;
            p+=2;
        }
        else
        {
            ans[n] = it;
            n+=2;
        }
    }
    return ans;
}
vector<int> RearrangebySign(vector<int>A, int n){ 
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){ 
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  // If positives are lesser than the negatives.
  if(pos.size() < neg.size()){ 
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0;i<pos.size();i++){
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    }
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        A[index] = neg[i];
        index++;
    }
  }
  // If negatives are lesser than the positives.
  else{   
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<neg.size();i++){
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    } 
    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        A[index] = pos[i];
        index++;
    }
  }
  return A;
    
}
int main()
{
    vector<int> nums = {3,1,-2,-5,2,-4};
    vector<int> ans = rearrangeArray(nums);
    for(auto it:ans) cout<<it<<" ";
}