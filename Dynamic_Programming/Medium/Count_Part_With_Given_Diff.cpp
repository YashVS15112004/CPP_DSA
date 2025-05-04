#include <bits/stdc++.h>
using namespace std;
int mod =(int)1e9+7;
int countPartitionsUtil_MEM(int ind, int target, vector<int>& arr, vector<vector
<int>> &dp){
     if(ind == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    if(dp[ind][target]!=-1)
        return dp[ind][target];  
    int notTaken = countPartitionsUtil_MEM(ind-1,target,arr,dp);
    int taken = 0;
    if(arr[ind]<=target)
        taken = countPartitionsUtil_MEM(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%mod;
}
int findWays_TAB(vector<int> &num, int tar){
    int n = num.size();
   vector<vector<int>> dp(n,vector<int>(tar+1,0));
   if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
   else dp[0][0] = 1;  // 1 case - not pick
   if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
   for(int ind = 1; ind<n; ind++){
       for(int target= 0; target<=tar; target++){
           int notTaken = dp[ind-1][target];
           int taken = 0;
               if(num[ind]<=target)
                   taken = dp[ind-1][target-num[ind]];
       
           dp[ind][target]= (notTaken + taken)%mod;
       }
   }
   return dp[n-1][tar];
}
int findWays_OPT(vector<int> &num, int tar){
    int n = num.size();
   vector<int> prev(tar+1,0);
   if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
   else prev[0] = 1;  // 1 case - not pick
   if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;  // 1 case -pick
   for(int ind = 1; ind<n; ind++){
       vector<int> cur(tar+1,0);
       for(int target= 0; target<=tar; target++){
           int notTaken = prev[target];
           int taken = 0;
               if(num[ind]<=target)
                   taken = prev[target-num[ind]];
           cur[target]= (notTaken + taken)%mod;
       }
       prev = cur;
   }
   return prev[tar];
}
int countPartitions(int d, vector<int>& arr){
    int n = arr.size();
    int totSum = 0;
    for(int i=0; i<n;i++){
        totSum += arr[i];
    }
    //Checking for edge cases
    if(totSum-d <0 || (totSum-d)%2 ) return 0;
    return findWays_OPT(arr,(totSum-d)/2);
}
int main() {
  vector<int> arr = {5,2,6,4};
  int d=3;                           
  cout<<"The number of subsets found are " <<countPartitions(d,arr);
}
