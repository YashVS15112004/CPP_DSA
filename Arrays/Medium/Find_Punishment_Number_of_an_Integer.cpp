#include<bits/stdc++.h>
using namespace std;
int Pun(vector<int>&arr,int goal,int summ,int in){
        if(arr.size()==in){
            return summ==goal;
        }
        int num=0;
        for(int i=in;i<arr.size();i++){
            num=num*10+arr[i];
            if(summ+num>goal)break;
            if(Pun(arr,goal,summ+num,i+1))return true;
        }
        return false;
    }
int punishmentNumber(int n) {
        int punish=0;
        vector<int>arr;
        for(int i=1;i<=n;i++){
            int newn=i*i,temp=newn;
            while(temp>0){
                arr.insert(arr.begin(),temp%10);
                temp/=10;
            }
            // int summ=accumulate(arr.begin(),arr.end(),0);
            //while()
            if(Pun(arr,i,0,0)==1)punish+=i*i;
            arr.clear();
        }
        return punish;
    }
int main()
{
    int n = 37;
    cout<<punishmentNumber(n);
}