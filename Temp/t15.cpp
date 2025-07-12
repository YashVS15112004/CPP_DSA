#include <bits/stdc++.h>
using namespace std;

// Custom hash for pair<int,int>
struct hash_pair
{
    size_t operator()(const pair<int, int> &p) const
    {
        size_t h1 = hash<int>{}(p.first);
        size_t h2 = hash<int>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

// Provided BFS function adapted to return distance
int bfs_provided(int startX, int startY, int targetX, int targetY, int N, int M, const unordered_set<pair<int, int>, hash_pair> &blocked)
{
    if (startX == targetX && startY == targetY)
        return 0;

    queue<pair<pair<int, int>, int>> q;
    set<pair<int, int>> visited;

    q.push({{startX, startY}, 0});
    visited.insert({startX, startY});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        int x = curr.first.first;
        int y = curr.first.second;
        int dist = curr.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M &&
                blocked.find({nx, ny}) == blocked.end() &&
                visited.find({nx, ny}) == visited.end())
            {

                if (nx == targetX && ny == targetY)
                {
                    return dist + 1;
                }

                visited.insert({nx, ny});
                q.push({{nx, ny}, dist + 1});
            }
        }
    }
    return INT_MAX;
}

// Optimal BFS from target
unordered_map<pair<int, int>, int, hash_pair> bfs_from_target(int targetX, int targetY, int N, int M, const unordered_set<pair<int, int>, hash_pair> &blocked)
{
    unordered_map<pair<int, int>, int, hash_pair> distance;
    unordered_set<pair<int, int>, hash_pair> visited;
    queue<pair<int, int>> q;

    q.push({targetX, targetY});
    distance[{targetX, targetY}] = 0;
    visited.insert({targetX, targetY});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        int dist = distance[{x, y}];

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M &&
                blocked.find({nx, ny}) == blocked.end() &&
                visited.find({nx, ny}) == visited.end())
            {

                distance[{nx, ny}] = dist + 1;
                visited.insert({nx, ny});
                q.push({nx, ny});
            }
        }
    }
    return distance;
}

// Generate a random test case
tuple<int, int, int, vector<pair<int, int>>, int, unordered_set<pair<int, int>, hash_pair>, pair<int, int>> generate_test_case(int test_num)
{
    srand(time(0) + test_num); // Seed differently for each test

    int N = (rand() % 100) + 1;               // Small N for practicality
    int M = (rand() % (100000 / N)) + 1;      // Ensure N*M <= 10^5
    int K = (N >= 2) ? 2 : 1;                 // K=2 if possible, else 1
    int L = rand() % min(100, N * M - K - 1); // Up to 100 blockages

    vector<pair<int, int>> friends;
    unordered_set<pair<int, int>, hash_pair> blocked;
    set<pair<int, int>> occupied; // To ensure distinct positions

    // Generate distinct friend positions
    for (int i = 0; i < K; i++)
    {
        pair<int, int> pos;
        do
        {
            pos = {rand() % N + 1, rand() % M + 1};
        } while (occupied.count(pos));
        friends.push_back(pos);
        occupied.insert(pos);
    }

    // Generate blocked cells
    for (int i = 0; i < L; i++)
    {
        pair<int, int> pos;
        do
        {
            pos = {rand() % N + 1, rand() % M + 1};
        } while (occupied.count(pos));
        blocked.insert(pos);
        occupied.insert(pos);
    }

    // Generate target position
    pair<int, int> target;
    do
    {
        target = {rand() % N + 1, rand() % M + 1};
    } while (occupied.count(target));

    return {N, M, K, friends, L, blocked, target};
}

int main()
{
    const int NUM_TESTS = 600;
    int passed = 0;

    for (int t = 1; t <= NUM_TESTS; t++)
    {
        auto [N, M, K, friends, L, blocked, target] = generate_test_case(t);
        int targetX = target.first;
        int targetY = target.second;

        // Run optimal solution
        auto distance = bfs_from_target(targetX, targetY, N, M, blocked);
        int min_dist_optimal = INT_MAX;
        for (const auto &f : friends)
        {
            if (distance.count(f))
            {
                min_dist_optimal = min(min_dist_optimal, distance[f]);
            }
        }

        // Simulate provided code
        int minTime = INT_MAX;
        pair<int, int> bestPosition;
        for (const auto &f : friends)
        {
            int time = bfs_provided(f.first, f.second, targetX, targetY, N, M, blocked);
            if (time < minTime)
            {
                minTime = time;
                bestPosition = f;
            }
        }

        // Verify
        bool test_passed = false;
        if (minTime != INT_MAX && distance.count(bestPosition) && distance[bestPosition] == min_dist_optimal)
        {
            test_passed = true;
            passed++;
        }

        cout << "Test " << t << ": " << (test_passed ? "PASSED" : "FAILED") << endl;
        if (!test_passed)
        {
            cout << "N=" << N << ", M=" << M << ", K=" << K << ", L=" << L << endl;
            cout << "Target: (" << targetX << "," << targetY << ")" << endl;
            cout << "Selected: (" << bestPosition.first << "," << bestPosition.second << ") with time " << minTime << endl;
            cout << "Expected min distance: " << min_dist_optimal << endl;
        }
    }

    cout << "\nSummary: " << passed << " out of " << NUM_TESTS << " tests passed." << endl;
    if (passed == NUM_TESTS)
    {
        cout << "The code works correctly for all test cases." << endl;
    }
    else
    {
        cout << "The code has issues that need to be fixed." << endl;
    }

    return 0;
}