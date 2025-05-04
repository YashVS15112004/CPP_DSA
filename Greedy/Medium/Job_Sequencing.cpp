#include<bits/stdc++.h>
using namespace std;
struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
bool static cmp(Job j1,Job j2)
{
    if(j1.profit>j2.profit) return true;
    return false;
}
vector<int> JobScheduling(Job jobs[], int n) {
    sort(jobs,jobs+n,cmp);
    vector<int> ans (2,0);
    int mxd = 0;
    for(int i=0;i<n;i++) mxd = max(mxd,jobs[i].deadline);
    vector<int> jbs (mxd+1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=jobs[i].deadline;j>=1;j--)
        {
            if(jbs[j]==0) 
            {
                jbs[j] = jobs[i].profit;
                ans[0]++;
                ans[1] += jobs[i].profit;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    Job jobs[] = {
        {1, 11, 321},
        {2, 2, 62},
        {3, 5, 456},
        {4, 8, 394},
        {5, 11, 424},
        {6, 10, 22},
        {7, 1, 393},
        {8, 6, 87},
        {9, 3, 118},
        {10, 8, 384},
        {11, 10, 83}
    };
    vector<int> ans = JobScheduling(jobs,11);
    cout<<ans[0]<<" "<<ans[1];
}