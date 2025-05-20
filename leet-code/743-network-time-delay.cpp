
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Create adjacency list
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
        }

        // Step 2: Min-Heap (Priority Queue) -> {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k}); // Start from node k with distance 0

        // Step 3: Distance Array (Initialized to INT_MAX)
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Step 4: Process Nodes in Priority Queue
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node]) continue; // Ignore outdated entries

            for (auto& [neighbor, weight] : graph[node]) {
                int newTime = time + weight;
                if (newTime < dist[neighbor]) {  // Found a shorter path
                    dist[neighbor] = newTime;
                    pq.push({newTime, neighbor});
                }
            }
        }

        // Step 5: Get the Maximum Distance
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1; // If any node is unreachable
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};

int networkTimeDelay(vector<vector<int>>& times, int n, int k)
{
    vector<vector<int>>adj(n);
    
    for (const vector<int>& edge: times)
    {
        printf("src: %d, dest: %d, time: %d\n", edge[0], edge[1], edge[2]);
    }


    return 0;
};



int main()
{
    vector<vector<int>> times = {{1, 2, 3}};

    networkTimeDelay(times, 4, 2);
    return 0;
}
