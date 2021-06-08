#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main()
{
	vector<vector<int>> adj_matrix;
	int n,m;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	adj_matrix.resize(n + 1, vector<int>(n + 1, numeric_limits<int>::max()));
	for (int i = 0; i <= n; ++i){
		adj_matrix[i][i] = 1;
	}
	while (m--){
		int v, u;
		cin >> v >> u;
		adj_matrix[v][u] = 1;
	}
	for (int k = 1; k <= n; ++k){
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				if (adj_matrix[i][k] != numeric_limits<int>::max() && adj_matrix[k][j] != numeric_limits<int>::max())
					adj_matrix[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i){
		int cnt = 0;
		for (int j = 1; j <= n; ++j) {
			if (adj_matrix[i][j] == numeric_limits<int>::max()&&adj_matrix[j][i]==numeric_limits<int>::max())
				++cnt;
		}
		cout << cnt << "\n";
	}
	return 0;
}
