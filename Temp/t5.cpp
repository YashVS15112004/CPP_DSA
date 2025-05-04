#include <bits/stdc++.h>
using namespace std;
int numRabbits(vector<int> &answers)
{
    unordered_map<int, int> mp;
    int ans = 0;
    for (auto it : answers)
        mp[it]++;
    for (auto it : mp)
    {
        if (it.first == 0)
            ans += it.second;
        else if (it.first + 1 >= it.second)
            ans += (it.first + 1);
        else
        {
            int div = it.first + 1;
            int quo = it.second / div;
            int rem = it.second % div;
            rem = (rem!=0)?div:0;
            ans += (quo * div) + rem;
        }
    }
    return ans;
}
int main()
{
    vector<int> answers = {0, 0, 1, 1, 1};
    cout << numRabbits(answers);
}