from math import ceil, log2

"""
Find LCA using binary lifting method

1. initialize tree
2. initialize the dp array
3. populate tree and and level array
4. if on different level bring both nodes on same level
5. find k'th ancestor common to both nodes  
"""

class Tree:
    def __init__(self, n):
        self.height = ceil(log2(n))

        # list to hold tree elements
        self.g = [0]*(n+1)
        for i in range(n+1):
            self.g[i] = []
        # list to hold ancestors
        self.dp = [0]*(n+1)
        for i in range(n+1):
            self.dp[i] = [-1]*(self.height+1)

        # list to store level of each node
        self.level = [0]*(n+1)

    def dfs(self, u, p):
        self.dp[u][0] = p
        for i in range(1, self.height+1):
            self.dp[u][i] = self.dp[self.dp[u][i-1]][i-1]

        for v in self.g[u]:
            if v != p:
                self.level[v] = self.level[u]+1
                self.dfs(v, u)

    def lca(self, u, v):

        if self.level[u] < self.level[v]:
            u, v = v, u

        d = self.level[u] - self.level[v]
        if d:
            for parent in range(self.height + 1):
                if d & 1 << parent:
                    u = self.dp[u][parent]

        if u == v:
            return u

        for i in range(self.height, -1, -1):
            if self.dp[u][i] != self.dp[v][i]:
                u = self.dp[u][i]
                v = self.dp[v][i]
        return self.dp[u][0]

if __name__ == '__main__':
    n, q = map(int, input().split())
    t = Tree(n)
    sets = []
    for i in range(n-1):
        u, v = map(int, input().split())
        t.g[u].append(v)
    for i in range(q):
        input()
        sets.append(set(map(int, input().split())))
    t.dfs(1, 1)
    print(t.lca(6,5))
