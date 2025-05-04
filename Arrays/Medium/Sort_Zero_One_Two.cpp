#include<bits/stdc++.h>
using namespace std;
void better(vector<int> &nums)
{
    int zero=0,one=0,two=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) zero++;
            else if(nums[i]==1) one++;
            else two++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(zero>0)
            {
                nums[i] = 0;
                zero--;
            }
            else if(one>0)
            {
                nums[i] = 1;
                one--;
            }
            else if(two>0)
            {
                nums[i] = 2;
                two--;
            }
        }
}
void optimal(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1; // 3 pointers

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main()
{
    int n = 6;
    vector<int> nums = {0, 2, 1, 2, 0, 1};
    optimal(nums);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}