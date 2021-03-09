#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
백준 1761
문제
N(2 ≤ N ≤ 40,000)개의 정점으로 이루어진 트리가 주어지고 
M(1 ≤ M ≤ 10,000)개의 두 노드 쌍을 입력받을 때 두 노드 사이의 거리를 출력하라.

입력
첫째 줄에 노드의 개수 N이 입력되고 
다음 N-1개의 줄에트리 상에 연결된 두 점과 거리를 입력받는다
그 다음 줄에 M이 주어지고
다음 M개의 줄에 거리를 알고 싶은 노드 쌍이 한 줄에 한 쌍씩 입력된다.
두 점 사이의 거리는 10,000보다 작거나 같은 자연수이다.

정점은 1번부터 N번까지 번호가 매겨져 있다.

출력
M개의 줄에 차례대로 입력받은 두 노드 사이의 거리를 출력한다.

*/


void DFS(vector<list<pair<int, int>>>& graph,  vector<int>& tree,vector<int>& depth,vector<int>& cost, int prv, int now, int c);
int LCA(vector<int>& tree, vector<int>& depth, vector<vector<int>>& dp,int v, int u, int height);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, height=0;
	vector<list<pair<int, int>>> graph;
	vector<int> tree, depth,cost;
	vector<vector<int>> dp;
	cin >> N;
	while ((1 << height) <= N)height++;
	dp.resize(N+1, vector<int>(height+1));
	graph.resize(N + 1);
	depth.resize(N + 1);
	cost.resize(N + 1);
	tree.resize(N + 1);
	for (int i = 0; i < N-1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({ v,c });
		graph[v].push_back({ u,c });
	}
	DFS(graph, tree, depth, cost, 1, 1, 0);
	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = tree[i];
	}
	for (int level = 1; level <= height; level++)
	{
		for (int i = 1; i <= N; i++)
		{
			dp[i][level] = dp[dp[i][level - 1]][level - 1];
		}
	}
	cin >> M;
	while (M--)
	{
		int u, v;
		cin >> u >> v;
		int lca = LCA(tree,depth, dp, v, u, height);
		cout << cost[u] + cost[v] - (2 * cost[lca])<<'\n';
	}
	return 0;
}

void DFS(vector<list<pair<int, int>>>& graph, vector<int>& tree, vector<int>& depth, vector<int>& cost,int prv, int now, int c)
{
	tree[now] = prv;
	depth[now] = depth[prv] + 1;
	cost[now] = c;
	for (auto& v : graph[now])
	{
		if (v.first == prv) continue;
		DFS(graph, tree, depth, cost, now, v.first, c+v.second);
	}
}

int LCA(vector<int>& tree, vector<int>& depth, vector<vector<int>>& dp, int v, int u, int height)
{
	int low, high,h;
	if (depth[u] > depth[v])
	{
		low = u;
		high = v;
	}
	else
	{
		low = v;
		high = u;
	}
	int diff = depth[low] - depth[high];
	for (int i = 0; diff; i++)
	{
		if (diff & 1)low = dp[low][i];
		diff = diff >> 1;
	}
	if (low == high) return low;
	for (h = height; h > -1; h--)
	{
		if (dp[low][h] != dp[high][h])
		{
			low = dp[low][h];
			high = dp[high][h];
		}
	}
	return dp[low][0];
}
