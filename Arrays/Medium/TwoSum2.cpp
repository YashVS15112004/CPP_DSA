#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    if(n<=1) return {-1,-1};
    int low = 0;
    int high = n-1;
    while(low<high)
    {
        if(numbers[low]+numbers[high]>target) high--;
        else if(numbers[low]+numbers[high]<target) low++;
        else return {low+1,high+1};
    }
    return {-1,-1};
}
int  main()
{
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSum(numbers,target);
    cout<<ans[0]<<" , "<<ans[1]<<endl;
}