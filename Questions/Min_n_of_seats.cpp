#include<bits/stdc++.h>
using namespace std;
int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int n = seats.size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            int temp = (seats[i]-students[i]);
            if(temp<0)
            {
                temp = 0-temp;
            }
            cnt += temp;
        }
        return cnt;    
}
int main()
{
    vector<int> s = {3,1,5};
    vector<int> t = {2,7,4};
    cout<<minMovesToSeat(s,t)<<endl;
}