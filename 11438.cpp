#include <vector>
#include <list>
#include <iostream>
#include <cmath>
using namespace std;

void MakeTree(int p, int depth, vector<vector<int>>& connect, vector<bool>& visited, vector<int>& depthes, vector<vector<int>>& tree);
int Find(int x, int y, vector<int>& depth, vector<vector<int>>& tree);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<int>> connect;
	vector<vector<int>> tree;	//tree[i][k]= i의 2^k번째 부모 정점
	vector<int> depth;
	vector<bool> visited;
	int N, M, max_k;
	cin >> N;
	max_k = (int)log2(N);
	connect.resize(N + 1);
	visited.resize(N + 1,false);
	tree.resize(N + 1, vector<int>(max_k+1,1));
	depth.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		connect[v2].push_back(v1);
		connect[v1].push_back(v2);
	}
	tree[1][0] = 1;
	MakeTree(1, 0, connect, visited, depth, tree);

	//tree 갱신
	for (int k = 1; k <= max_k; k++) {
		for (int i = 1; i <= N; i++) {
			tree[i][k] = tree[tree[i][k - 1]][k - 1];
		}
	}
	cin >> M;
	while (M--) {
		int x, y;
		cin >> x >> y;
		cout << Find(x, y, depth, tree)<<'\n';
	}
	return 0;
}

void MakeTree(int p, int depth, vector<vector<int>>& connect, vector<bool>& visited, vector<int>& depthes, vector<vector<int>>& tree) {
	visited[p] = true;
	depthes[p] = depth;
	for (int next : connect[p]) {
		if (visited[next])continue;
		tree[next][0] = p;
		MakeTree(next, depth + 1, connect, visited, depthes, tree);
	}
}

int Find(int x, int y, vector<int>& depth, vector<vector<int>>& tree) {
	//y가 더 깊게
	if (depth[y] < depth[x]) {
		swap(y, x);
	}
	int max_k = tree[0].size()-1;
	for (int k = max_k; k >= 0; k--) {
		int dif = depth[y] - depth[x];
		if (dif >= (1 << k)) {
			y = tree[y][k];
		}
	}
	if (x == y)return x;
	for (int k = max_k; k >= 0; k--) {
		if (tree[y][k] != tree[x][k]) {
			x = tree[x][k];
			y = tree[y][k];
		}
	}
	return tree[x][0];
}
