#include<bits/stdc++.h>
using namespace std;
int findMaxIndex(vector<vector<int>> &g, int n, int m, int col) {
    int maxValue = -1;
    int index = -1;
    //find the max element:
    for (int i = 0; i < n; i++) {
        if (g[i][col] > maxValue) {
            maxValue = g[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &g) {
    int n = g.size(), m = g[0].size();
    //apply binary search:
    int low = 0, high = m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int maxRowIndex = findMaxIndex(g, n, m, mid);
        int left = mid - 1 >= 0 ? g[maxRowIndex][mid - 1] : -1;
        int right = mid + 1 < m ? g[maxRowIndex][mid + 1] : -1;

        if (g[maxRowIndex][mid] > left && g[maxRowIndex][mid] > right) {
            //location of peak element:
            return {maxRowIndex, mid};
        }
        else if (g[maxRowIndex][mid] < left) high = mid - 1;
        else low = mid + 1;
    }
    //dummy return statement:
    return { -1, -1};
}
int main() {
    vector<vector<int>> g = {{8, 6}, {10, 1}};
    vector<int> ans = findPeakGrid(g);
    cout << "The peak element is at: {" << ans[0] << ", "
            << ans[1] << "}" << endl;
    return 0;
}