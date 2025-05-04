#include<bits/stdc++.h>
using namespace std;
vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
{
    int n = items.size(),m = queries.size(),maxc = 0;
    sort(items.begin(),items.end());
    vector<int> ans;
    map<int,int> mpp;
    for(auto it:items) 
    {
        int mxe = max(it[1],mpp[it[0]]);
        mpp[it[0]] = max(maxc,mxe);
        maxc = mpp[it[0]];
    }
    pair<int,int> se;
    vector<pair<int,int>> vec;
    for(auto it:mpp) vec.push_back({it.first,it.second});
    se = {vec[0].first,vec[0].second};
    mpp.clear();
    maxc = 0;
    for(int i=0;i<m;i++)
    {
        if(queries[i]>=se.first) maxc = se.second;
        else maxc = 0;
        int target = queries[i],low=0,high=vec.size()-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(target==vec[mid].first){
                maxc = vec[mid].second;
                break;
            }
            else if(target>vec[mid].first) 
            {
                maxc = max(maxc,vec[mid].second);
                low = mid+1;
            }
            else high = mid-1;
        }
        ans.push_back(maxc);
    }
    return ans;
}
int main()
{
    vector<vector<int>> items = {
    {193, 732}, {781, 962}, {864, 954}, {749, 627}, {136, 746},
    {478, 548}, {640, 908}, {210, 799}, {567, 715}, {914, 388},
    {487, 853}, {533, 554}, {247, 919}, {958, 150}, {193, 523},
    {176, 656}, {395, 469}, {763, 821}, {542, 946}, {701, 676}
};

vector<int> queries = {
    885, 1445, 1580, 1309, 205, 1788, 1214, 1404, 572, 1170,
    989, 265, 153, 151, 1479, 1180, 875, 276, 1584
};
    vector<int> ans = maximumBeauty(items,queries);
    for(auto it:ans) cout<<it<<" ";
}