#include <list>
#include <queue>
#include <iostream>

using namespace std;

void DFS(vector<list<int>>& g, int s, vector<bool>& visited);
void BFS(vector<list<int>>& g, int s);
int main() {
	vector<list<int>> g;
	vector<bool> visited;
	int N, M,s;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> s;
	g.resize(N + 1);
	visited.resize(N + 1, false);
	while (M--) {
		int v, w;
		cin >> v >> w;
		g[v].push_back(w);
		g[w].push_back(v);
	}
	for (auto iter = g.begin(); iter != g.end(); iter++) {
		iter->sort();
	}
	DFS(g, s, visited);
	cout << '\n';
	BFS(g, s);
	return 0;
}

void DFS(vector<list<int>>& g, int s, vector<bool>& visited) {
	cout << s << ' ';
	visited[s] = true;
	for (auto iter = g[s].begin(); iter != g[s].end(); iter++) {
		if (visited[*iter])continue;
		DFS(g, *iter, visited);
	}
}

void BFS(vector<list<int>>& g, int s) {
	vector<bool> visited(g.size(), false);
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty()) {
		int v = q.front();
		cout << v << ' ';
		q.pop();
		for (auto iter = g[v].begin(); iter != g[v].end(); iter++) {
			if (visited[*iter])continue;
			q.push(*iter);
			visited[*iter] = true;
		}
	}
}
