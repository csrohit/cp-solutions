#include <cstdio>
#include <vector>
#include <functional>

using std::vector;

class Solution
{
  public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        /* Build adjacency matrix */
        int                 n = roads.size() + 1;
        vector<vector<int>> adj(n);

        for (const vector<int> &road : roads)
        {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }

        /* DFS to calculate fuel */
        long long    fuel = 0;
        vector<bool> visited(n, false);

        std::function<long long(int, int)> dfs = [&](int node, int parent)
        {
            long long people = 1;
            visited[node]    = true;

            for (const int el : adj[node])
            {
                if (el != parent)
                {
                    people += dfs(el, node);
                }
            }

            if (node != 0)
            {
                fuel += ceil((double_t)people / seats);
            }

            return people;
        };
        dfs(0, -1);
        return fuel;
    }
};

int main()
{

    vector<vector<int>> roads = {{0, 1}, {0, 2}, {0, 3}};
    int                 seats = 5;

    printf("Minimum fuel cost: %lld\n", Solution().minimumFuelCost(roads, seats));

    return (0);
}
