#include <bits/stdc++.h>
using namespace std;
int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    vector<int> v1(7, 0), v2(7, 0);
    int n = tops.size(), e1 = 0, e2 = 0, ce1 = 0, ce2 = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        v1[tops[i]]++;
        v2[bottoms[i]]++;
    }
    for (int i = 1; i < 7; i++)
    {
        if (ce1 < v1[i])
        {
            ce1 = v1[i];
            e1 = i;
        }
        if (ce2 < v2[i])
        {
            ce2 = v2[i];
            e2 = i;
        }
    }
    cout << ce1 << " " << e1 << endl;
    cout << ce2 << " " << e2 << endl;
    if (ce1 > ce2)
    {
        for (int i = 0; i < n; i++)
        {
            if (e1 == tops[i])
                continue;
            else if (e1 != tops[i] && e1 == bottoms[i])
                ans++;
            else if (e1 != tops[i] && e1 != bottoms[i])
                return -1;
        }
    }
    else if (ce1 < ce2)
    {
        for (int i = 0; i < n; i++)
        {
            if (e2 == bottoms[i])
                continue;
            else if (e2 != bottoms[i] && e2 == tops[i])
                ans++;
            else if (e2 != bottoms[i] && e2 != tops[i])
                return -1;
        }
    }
    else
    {
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++)
        {
            if(ans1==1e9 && ans2==1e9) return -1;
            if (e1 != tops[i] && e1 == bottoms[i])
                ans1++;
            else if (e1 != tops[i] && e1 != bottoms[i])
                ans1 = 1e9;
            if (e2 != bottoms[i] && e2 == tops[i])
                ans2++;
            else if (e2 != bottoms[i] && e2 != tops[i])
                ans2 = 1e9;
        }
        ans = min(ans1, ans2);
    }
    return ans;
}
int main()
{
    vector<int> tops = {2,1,1,3,3,1,2,2,2,3,3,3,2,2,2,1,1,1,3,1,1,1,1,2,3,3,3,2,2,3,2,2,2,2,2,1,1,2,1,1,1,3,1,2,2,1,2,2,1,2,1,3,2,1,3,1,1,2,2,2,1,2,1,2,2,3,2,3,2,2,2,3,3,1,1,2,1,2,1,2,3,3,3,1,1,1,1,3,2,2,1,2,1,3,2,2,1,1,1,3},bottoms = {3,3,1,3,3,2,2,2,1,3,2,3,3,3,1,1,2,1,1,2,1,2,2,1,3,1,2,1,2,2,2,3,3,3,3,2,3,3,2,1,3,2,2,3,2,2,2,2,3,2,3,2,2,3,2,1,3,3,2,1,2,1,2,3,3,3,3,3,2,3,2,2,2,2,3,2,1,3,1,1,3,3,3,2,3,1,3,3,1,3,1,2,3,1,1,3,3,1,2,2};
    cout<<minDominoRotations(tops,bottoms);
}