#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void rev(int arr[],int i,int n)
{
    if(n<=i)
    return;

    swap(arr[i],arr[n-1]);
    return rev(arr,i+1,n-1);

}
int main()
{
   int arr[] = {1,2,3,4,5};
   rev(arr,0,5);
   for(int i=0;i<5;i++)
   {
        cout<<arr[i]<<" ";
   }
}