#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int time_ans = -1;
int edge_ans = 0;
int n, m;
vector<bool> visited;	
vector<vector<bool>> edge_visited;
vector<list<pair<int, int>>> graph;
vector<int> cost;
int DFS_SerchMaxTime(int s, int e, int now);
int DFS_SerchEdge(int s, int now, int cost);
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	visited.resize(n + 1,  false);
	edge_visited.resize(n + 1, vector<bool>(n + 1, false));
	graph.resize(n + 1);
	cost.resize(n + 1);
	int s, e;
	for (int i = 0; i < m; i++)
	{
		int source, dest, cost;
		cin >> source >> dest >> cost;
		graph[source].push_back({ dest, cost });
	}
	cin >> s >> e;
	cout << DFS_SerchMaxTime(s, e, s) << '\n'<< DFS_SerchEdge(s, s, 0)-1;
	return 0;
}

int DFS_SerchMaxTime(int s, int e, int now)
{
	if (e == now)
	{
		return 0;
	}
	for (auto& v : graph[now])
	{
		if (visited[v.first])
		{
			cost[now] = max(cost[now], cost[v.first] + v.second);
		}
		else
		{
			cost[now] = max(cost[now], DFS_SerchMaxTime(s, e, v.first) + v.second);
		}
	}
	visited[now] = true;
	return cost[now];
}

int DFS_SerchEdge(int s, int now, int time)
{
	int ret = 0;
	if (cost[now] + time == cost[s])
	{
		ret += 1;
	}
	else
	{
		return 0;
	}
	for (auto v : graph[now])
	{
		if (edge_visited[now][v.first] == false)
		{
			ret += DFS_SerchEdge(s, v.first, time + v.second);
			edge_visited[now][v.first] = true;
		}
	}
	return ret;
}
