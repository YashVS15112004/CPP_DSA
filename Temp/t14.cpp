// test_solution.cpp
#include <bits/stdc++.h>
using namespace std;

// hash for pair<int,int>
struct hash_pair {
    size_t operator()(const pair<int, int> &p) const {
        size_t h1 = hash<int>{}(p.first);
        size_t h2 = hash<int>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

// Brute BFS from a friend to target
int bfs_provided(int startX, int startY,
                 int targetX, int targetY,
                 int N, int M,
                 const unordered_set<pair<int, int>, hash_pair> &blocked)
{
    if (startX == targetX && startY == targetY)
        return 0;
    queue<pair<pair<int,int>,int>> q;
    unordered_set<pair<int,int>,hash_pair> vis;
    q.push({{startX,startY},0});
    vis.insert({startX,startY});
    int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x=cur.first.first, y=cur.first.second, d=cur.second;
        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            auto pn = make_pair(nx,ny);
            if(nx>=1&&nx<=N&&ny>=1&&ny<=M
               && blocked.find(pn)==blocked.end()
               && vis.find(pn)==vis.end())
            {
                if(nx==targetX && ny==targetY)
                    return d+1;
                vis.insert(pn);
                q.push({pn,d+1});
            }
        }
    }
    return INT_MAX;
}

// Optimal BFS from target to all cells
unordered_map<pair<int,int>,int,hash_pair>
bfs_from_target(int targetX, int targetY,
                int N, int M,
                const unordered_set<pair<int,int>,hash_pair> &blocked)
{
    unordered_map<pair<int,int>,int,hash_pair> dist;
    unordered_set<pair<int,int>,hash_pair> vis;
    queue<pair<int,int>> q;
    q.push({targetX,targetY});
    dist[{targetX,targetY}] = 0;
    vis.insert({targetX,targetY});
    int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
    while(!q.empty()){
        auto p = q.front(); q.pop();
        int x=p.first, y=p.second, d=dist[p];
        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            auto pn = make_pair(nx,ny);
            if(nx>=1&&nx<=N&&ny>=1&&ny<=M
               && blocked.find(pn)==blocked.end()
               && vis.find(pn)==vis.end())
            {
                dist[pn] = d+1;
                vis.insert(pn);
                q.push(pn);
            }
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // random generator
    mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dN(1,1000), dM(1,1000);
    const int TESTS = 600;

    int passed = 0, failed = 0;
    for(int t=1; t<=TESTS; t++){
        // generate dimensions with N*M <= 100k
        int N = dN(rng);
        int M = min(dM(rng), 100000 / max(1, N));

        // friends
        int K = uniform_int_distribution<int>(1, min(N,20))(rng);
        vector<pair<int,int>> friends(K);
        for(int i=0;i<K;i++){
            friends[i].first  = uniform_int_distribution<int>(1,N)(rng);
            friends[i].second = uniform_int_distribution<int>(1,M)(rng);
        }

        // blocked cells up to 100
        int maxB = min(N*M - 1, 100);
        int L = uniform_int_distribution<int>(0, maxB)(rng);
        unordered_set<pair<int,int>,hash_pair> blocked;
        while((int)blocked.size() < L){
            int bx = uniform_int_distribution<int>(1,N)(rng);
            int by = uniform_int_distribution<int>(1,M)(rng);
            blocked.emplace(bx,by);
        }

        // target
        int tx, ty;
        do {
            tx = uniform_int_distribution<int>(1,N)(rng);
            ty = uniform_int_distribution<int>(1,M)(rng);
        } while(blocked.count({tx,ty}));

        // brute solve
        int bestDb = INT_MAX;
        pair<int,int> ansB = {-1,-1};
        for(auto &f : friends){
            int d = bfs_provided(f.first, f.second, tx, ty, N, M, blocked);
            if(d < bestDb){
                bestDb = d;
                ansB = f;
            }
        }

        // optimal solve
        auto dist_map = bfs_from_target(tx, ty, N, M, blocked);
        int bestDo = INT_MAX;
        pair<int,int> ansO = {-1,-1};
        for(auto &f : friends){
            auto it = dist_map.find(f);
            if(it != dist_map.end() && it->second < bestDo){
                bestDo = it->second;
                ansO = f;
            }
        }

        // compare and report
        if(ansB == ansO){
            cout << "Test #" << t << ": PASS\n";
            passed++;
        } else {
            cout << "Test #" << t << ": FAIL\n";
            cout << "  N=" << N << " M=" << M << "\n";
            cout << "  Friends:";
            for(auto &f : friends)
                cout << " ("<<f.first<<","<<f.second<<")";
            cout << "\n  Blocked:";
            for(auto &b : blocked)
                cout << " ("<<b.first<<","<<b.second<<")";
            cout << "\n  Target=("<<tx<<","<<ty<<")\n";
            cout << "  Brute=("<<ansB.first<<","<<ansB.second<<") "
                 << "Optimal=("<<ansO.first<<","<<ansO.second<<")\n";
            failed++;
        }
    }

    cout << "\nSummary: " << passed << " passed, "
         << failed << " failed out of " << TESTS << " tests.\n";
    return 0;
}
