#include <bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &path)
    {
        vis[node] = 1;
        path[node] =  1;
        for(auto it:adj[node])
        {
            if(!vis[it])
			{
				if(dfs(it,adj,vis,path)==true) return true;
			} 
            else if(path[it]) return true;
        }
        path[node] = 0;
        return false;
    }
    bool isCyclic(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> vis (n,0);
        vector<int> path (n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,path)==true) return true;
            }
        }
        return false;
    }
int main() {
	vector<vector<int>> adj = {{1}, {2}, {3}, {3}};
	bool ans = isCyclic(adj);
	if (ans)
		cout << "True\n";
	else
		cout << "False\n";
	return 0;
}