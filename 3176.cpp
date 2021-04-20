#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

/*
백준 3176

*/

void MakeTree(int prv, int now, vector<list<pair<int, int>>>& graph, vector<int>& tree, vector<int>& depth, vector<vector<int>>& min_cost, vector<vector<int>>& max_cost, vector<vector<int>>& parent_dp)
{
    tree[now] = prv;
    depth[now] = depth[prv] + 1;
    for (auto& v : graph[now])
    {
        if (v.first == prv)continue;
        min_cost[v.first][0] = max_cost[v.first][0] = v.second;
        parent_dp[v.first][0] = now;
        MakeTree(now, v.first, graph, tree, depth, min_cost, max_cost, parent_dp);
    }
}

pair<int, int> GetAnswer(int v, int u, vector<int>& depth, vector<vector<int>>& min_cost, vector<vector<int>>& max_cost, vector<vector<int>>& parent_dp, int height);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, height = 0,v, u;
    vector<int> tree, depth;
    vector<list<pair<int, int>>> graph;
    vector<vector<int>> min_cost, max_cost, parent_dp;
    cin >> n;
    graph.resize(n + 1);
    while ((1 << height) <= n) height++;
    min_cost.resize(n + 1, vector<int>(height + 1, INT32_MAX));
    max_cost.resize(n + 1, vector<int>(height + 1));
    parent_dp.resize(n + 1, vector<int>(height + 1));
    tree.resize(n + 1);
    depth.resize(n + 1);
    for(int i=1;i<n;i++)
    {
        int l;
        cin >> v >> u >> l;
        graph[v].push_back({ u,l });
        graph[u].push_back({ v,l });
    }
    parent_dp[1][0] = 1;
    MakeTree(1, 1, graph, tree, depth, min_cost, max_cost, parent_dp);
    min_cost[1][0] = INT32_MAX;
    max_cost[1][0] = 0;
    for (int h = 1; h <= height; h++)
    {
        for (int v = 1; v <= n; v++)
        {
            parent_dp[v][h] = parent_dp[parent_dp[v][h - 1]][h - 1];
            min_cost[v][h] = min(min_cost[v][h - 1], min_cost[parent_dp[v][h - 1]][h - 1]);
            max_cost[v][h] = max(max_cost[v][h - 1], max_cost[parent_dp[v][h - 1]][h - 1]);
        }
    }
    cin >> k;
    while (k--)
    {
        cin >> u >> v;
        pair<int, int> ans = GetAnswer(v, u, depth, min_cost, max_cost, parent_dp, height);
        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}

pair<int, int> GetAnswer(int v, int u, vector<int>& depth, vector<vector<int>>& min_cost, vector<vector<int>>& max_cost, vector<vector<int>>& parent_dp, int height)
{
    int low, high, low_cost=INT32_MAX, high_cost=0;
    if (depth[v] > depth[u])
    {
        low = v;
        high = u;
    }
    else
    {
        low = u;
        high = v;
    }
    if (low == high)
    {
        return { 0,0 };
    }
    for (int h = height; h >= 0; h--)
    {
        if ((depth[low] - depth[high]) >= (1 << h))
        {
            low_cost = min(low_cost, min_cost[low][h]);
            high_cost = max(high_cost, max_cost[low][h]);
            low = parent_dp[low][h];
        }
    }
    if (low == high)
    {
        return { low_cost, high_cost };
    }
    for (int h = height; h >= 0; h--)
    {
        if (parent_dp[low][h] != parent_dp[high][h])
        {
            low_cost = min(low_cost, min(min_cost[low][h], min_cost[high][h]));
            high_cost = max(high_cost, max(max_cost[low][h], max_cost[high][h]));
            low = parent_dp[low][h]; high = parent_dp[high][h];
        }
    }
    low_cost = min(low_cost, min(min_cost[low][0], min_cost[high][0]));
    high_cost = max(high_cost, max(max_cost[low][0], max_cost[high][0]));
    return { low_cost, high_cost };
}
