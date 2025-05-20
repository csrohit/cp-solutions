#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
  public:
    int mostProfitablePath(const vector<vector<int>> &edges, const int bob, const vector<int> &amount)
    {
        int maxProfit = numeric_limits<int>::min();

        /* construct adjacency matrix */
        int                 n = amount.size();
        vector<vector<int>> adj(n);
        for (const vector<int> &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        /* Print adjacency matrix */
        // for (int i = 0; i < n; ++i)
        // {
        //     printf("%d ", i);
        //     for (const int element : adj[i])
        //     {
        //         printf("-> %d ", element);
        //     }
        //     printf("\n");
        // }

        vector<int> bobPath;

        /* DFS to find Bob's route */
        vector<int> visited(n, -1);
        vector<int> parent(n, -1);

        visited[0] = 0;

        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int currentNode = q.front();
            q.pop();

            /* check if reached bob */
            if (bob == currentNode)
            {
                // printf("Reached bob\n");

                /* Back track bob's path */
                while (-1 != currentNode)
                {
                    bobPath.push_back(currentNode);
                    currentNode = parent[currentNode];
                }
                break;
            }

            /* Mark node as visited */
            for (int nextNode : adj[currentNode])
            {
                /* only visit unvisited nodes */
                if (-1 == visited[nextNode])
                {
                    visited[nextNode] = visited[currentNode] + 1;
                    q.push(nextNode);

                    /* Track parent of visited nodes for backtracking */
                    parent[nextNode] = currentNode;
                    // printf("Next visiting node %d from parent %d\n", nextNode, currentNode);
                }
            }
        }

        // printf("Path of bob: ");
        // for (const int el : bobPath)
        // {
        //     printf("-> %d ", el);
        // }
        // printf("\n");

        std::function<int(int, int, int)> dfs = [&](int node, int parent, int time)
        {
            int bobTime = -1;
            int profit  = 0;

            /* If bob visited this node */
            for (int i = 0; i < bobPath.size(); ++i)
            {
                if (node == bobPath[i])
                {
                    bobTime = i;
                    break;
                }
            }

            if (-1 != bobTime)
            {
                // printf("Bob time to reach %d is %d and alice time %d\n", node, bobTime, time);
                if (time < bobTime)
                {
                    profit = amount[node];
                    // printf("Alice[%d] reached node %d before bob[%d], alice takes all profit[%d]\n", node, time, bobTime, amount[node]);
                }
                else if (bobTime == time)
                {
                    profit = amount[node] / 2;
                    // printf("Alice[%d] reached node %d same time as  bob[%d], alice shares the profit[%d]\n", node, time, bobTime, amount[node]);
                }
                else
                {
                    // printf("Alice[%d] reached node %d after bob[%d], Bob takes all the profit[%d]\n", node, time, bobTime, amount[node]);
                    profit = 0;
                }
            }
            else
            {
                // printf("Bob did not visit node %d, alice takes all profit[%d]\n", node, amount[node]);
                profit = amount[node];
            }

            /* Current node processing complete, process next nodes */
            int maxProfit = numeric_limits<int>::min();
            for (const int el : adj[node])
            {
                if (el != parent)
                {
                    maxProfit = max(maxProfit, dfs(el, node, time + 1));
                    // printf("Max profit returned from node %d is %d\n", el, maxProfit);
                }
            }

            return maxProfit == numeric_limits<int>::min() ? profit : profit + maxProfit;
        };

        return dfs(0, -1, 0);
    }
};

int main()
{
    vector<vector<int>> edges  = {{0, 1}, {1, 2}, {2, 3}};
    int                 bob    = 3;
    vector<int>         amount = {-5644, -6018, 1188, -8502};

    Solution sol;

    printf("Most profitable path: %d\n", sol.mostProfitablePath(edges, bob, amount));

    return 0;
}
