#include <stdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

const int maxn = 2e5 + 10;

vector<int> G[maxn];
vector<int> Q[maxn];
map<int, pair<int, int> > Node[maxn];
int dis[maxn];
int ans[maxn];

void update(int &a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}

void dfs(int u, int fa)
{
	for (int v : G[u])
	{
		if (v == fa)
			continue;
		dis[v] = dis[u] + 1;
		dfs(v, u);
	}
	for (int v : Q[u])
		Node[u][v] = make_pair(u, 1ll * dis[u] * u % mod);
	for (int v : G[u])
	{
		if (Node[u].size() < Node[v].size())
			swap(Node[u], Node[v]);
		for (auto p : Node[v])
		{
			int i = p.first;
			auto it = Node[u].find(i);
			if (it == Node[u].end())
			{
				Node[u].insert(p);
				continue;
			}
			long long a = p.second.first, b = p.second.second, c = it->second.first, d = it->second.second;
			update(ans[i], (a * d % mod + b * c % mod + mod - (2 * dis[u] * a % mod * c % mod) % mod) % mod);
			update(it->second.first, a);
			update(it->second.second, b);
		}
	}
}

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 0; i < q; ++i)
	{
		int k;
		scanf("%d", &k);
		while (k--)
		{
			int u;
			scanf("%d", &u);
			Q[u].push_back(i);
		}
	}
	dfs(1, 0);
	for (int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}