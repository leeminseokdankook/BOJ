#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#define KINDOFCANDY 1000000
using namespace std;

/*
백준 3830

*/

int find(int v, vector<int>& tree)
{
    if (v == tree[v])return v;
    else return tree[v]=find(tree[v], tree);
}

bool Merge(int u, int v, vector<int>& tree)
{
    int u_p = find(u, tree);
    int v_p = find(v,tree);
    if (u_p == v_p) return false;
    tree[v_p] = u_p;
    return true;
}

void DFS(int now, int weight, vector<bool>& visited, vector<list<pair<int, int>>>& graph, vector<int>& w)
{
    visited[now] = true;
    w[now] = weight;
    for (auto& v : graph[now])
    {
        if (visited[v.first])continue;
        DFS(v.first, weight + v.second, visited, graph, w);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    while (1)
    {
        char inst;
        int a, b;
        vector<int> tree, w;
        vector<bool> visited;
        vector<list<pair<int, int>>> graph;
        list<pair<int, int>> q;
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }
        tree.resize(n + 1);
        graph.resize(n + 1);
        visited.resize(n + 1);
        w.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            tree[i] = i;
            visited[i] = false;
        }
        while (m--) {
            cin >> inst >> a >> b;
            if (inst == '!')
            {
                int w;
                cin >> w;
                if (Merge(a, b, tree))
                {
                    graph[a].push_back({ b, w });
                    graph[b].push_back({ a, -w });
                }
            }
            else if (inst == '?')
            {
                if (find(a, tree) == find(b, tree))
                {
                    q.push_back({ a,b });
                }
                else
                {
                    q.push_back({ -1,-1 });
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == false) DFS(i, 0, visited, graph, w);
        }
        for (auto& p : q)
        {
            if (p.first == -1 && p.second == -1)
            {
                cout << "UNKNOWN\n";
            }
            else
            {
                cout << w[p.second] - w[p.first] << '\n';
            }
        }
    }
    return 0;
}
