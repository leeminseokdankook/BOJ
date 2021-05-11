#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<pair<int, int>> q;
	int n,s,p;
	int ans = 0, len = 1;
	int edge_cnt = 0;
	vector<vector<int>> tree;
	vector<bool> visited;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> s >> p;
	visited.resize(n + 1);
	tree.resize(n + 1);
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	q.push({ p,0 });
	visited[p] = true;
	while (q.empty() == false&&edge_cnt<2)
	{
		int vertex = q.front().first;
		int dis = q.front().second;
		q.pop();
		if (vertex <= s)
		{
			++edge_cnt;
			len += dis;
		}
		for (auto& next : tree[vertex])
		{
			if (visited[next] == false)
			{
				visited[next] = true;
				q.push({ next,dis+1 });
			}
		}
	}
	ans = n - len;
	cout << ans;
	return 0;
}
