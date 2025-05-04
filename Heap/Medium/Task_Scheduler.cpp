#include<bits/stdc++.h>
using namespace std;
int leastInterval(vector<char>& tasks, int n) {
vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }
        
        priority_queue<int> maxHeap;
        for (int cnt : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }
        
        int time = 0;
        queue<pair<int, int>> q;
        while (!maxHeap.empty() || !q.empty()) {
            time++;
            
            if (maxHeap.empty()) {
                time = q.front().second;
            } else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }
            
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
}
int main()
{
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout<<leastInterval(tasks,n);
}