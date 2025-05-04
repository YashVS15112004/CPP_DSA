#include<bits/stdc++.h>
using namespace std;
int smallestChair(vector<vector<int>>& times, int targetFriend) 
{
    vector<int> tf = times[targetFriend];
    sort(times.begin(),times.end());
    int n = times.size();
    vector<int> at;
    vector<int> dt;
    at.push_back(times[0][0]);
    dt.push_back(times[0][1]);
    if(at[0]==tf[0] && dt[0]==tf[1]) return 0;
    for(int i=1;i<n;i++)
    {
        bool flag = false;
        int time = INT_MAX;
        int tj;
        for(int j=0;j<dt.size();j++)
        {
            if(times[i][0]>=dt[j]) 
            {
                if(time>dt[j])
                {
                    tj = j;
                    time = dt[j];
                }
                flag = true;
            }
            if(flag==true)
            {
                at[tj] = times[i][0];
                dt[tj] = times[i][1];
                if(tf==times[i]) return tj;
                break;
            }
            
        }
        if(flag==false)
        {
            at.push_back(times[i][0]);
            dt.push_back(times[i][1]);
            if(tf==times[i]) return at.size()-1;
        }
    }
    return 1;
}
int main()
{
    vector<vector<int>> times = {{98198,99979},{94438,98042},{6104,64150},{15632,17378},{6923,88529},{68469,98315},{37973,86066},{90969,99746},{92396,96991},{53994,66509},{92972,97874},{70262,84374},{50387,64907},{99240,99985},{25642,56565},{7253,9683},{43669,68559},{60520,85461},{96567,97544},{64789,83994},{73723,84301},{55796,58566},{67943,78915},{92673,94868},{53570,58135},{69549,78461},{17694,75744},{9265,77868},{57880,89655},{23327,80521},{91232,91639},{91623,92961},{49501,88454},{88932,91622},{54965,59650},{46587,60025},{45140,98782},{47029,90516},{28112,29624},{73021,83152},{5377,19703},{70610,72191},{40633,66034},{87913,98864},{35913,50422},{39121,93376},{21100,79841},{8190,68139},{5140,54276},{22993,62342},{3491,8572},{70407,81025},{81198,96920},{29041,31796},{77060,81160},{94588,97686}};
    int targetFriend = 50;
    cout<<smallestChair(times,targetFriend);
}