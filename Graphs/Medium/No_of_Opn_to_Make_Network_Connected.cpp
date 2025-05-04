#include <bits/stdc++.h>
using namespace std;
class DS
{
    vector<int> size,parent;
    public:
    DS(int n)
    {
        size.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            size[i] = 1;
        } 
    }
    int findUP(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] = findUP(parent[node]);
    }
    void unionBySize(int u,int v)
    {
        int UP_u = findUP(u);
        int UP_v = findUP(v);
        if(UP_u==UP_v) return;
        else if(size[UP_u]<size[UP_v]) 
        {
            parent[UP_u] = UP_v;
            size[UP_v] += size[UP_u];
        }
        else 
        {
            parent[UP_v] = UP_u;
            size[UP_u] += size[UP_v];
        }
    }
};
int makeConnected(int n, vector<vector<int>>& connections) 
{
    int m = connections.size(),avc = 0,c = 0;
    DS ds(n);
    int src = connections[0][0];
    for(auto it:connections)
    {
        int u = it[0];
        int v = it[1];
        if(ds.findUP(u)==ds.findUP(v)) avc++;
        else ds.unionBySize(u,v);
    }
    // mn
    for(int i=0;i<n;i++) if(ds.findUP(i)==i) c++;
    c--;
    cout<<avc<<" "<<c<<endl;
    return (avc>=c)?c:-1;     
}
int main()
{
    int n = 8;
    vector<vector<int>> connections = {
        {0, 6}, {2, 3}, {2, 6}, {2, 7}, {1, 7},
        {2, 4}, {3, 5}, {0, 2}
    };
    cout<<makeConnected(n,connections);
}