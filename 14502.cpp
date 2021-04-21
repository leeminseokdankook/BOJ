#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

int BFS(vector<vector<int>>& lab);
int solve(vector<vector<int>>& lab, int sy, int sx, int cnt);

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	vector<vector<int>> lab;
	int N, M;
	cin >> N >> M;
	lab.resize(N);
	for (int row = 0; row < N; row++) {
		lab[row].resize(M);
		for (int col = 0; col < M; col++) {
			cin >> lab[row][col];
		}
	}
	int ans=0;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			if (lab[row][col] == 0) {
				lab[row][col] = 1;
				ans=max(solve(lab, row, col, 1), ans);
				lab[row][col] = 0;
			}
		}
	}
	cout << ans;
	return 0;
}


int solve(vector<vector<int>>& lab, int sy, int sx, int cnt) {
	if (cnt == 3) {
		return BFS(lab);
	}
	int ans = 0;
	for (int col = sx+1; col < lab[0].size(); col++) {
		if (lab[sy][col] == 0) {
			lab[sy][col] = 1;
			ans=max(solve(lab, sy, col, cnt + 1), ans);
			lab[sy][col] = 0;
		}
	}
	for (int row = sy+1; row < lab.size(); row++) {
		for (int col = 0; col < lab[0].size(); col++) {
			if (lab[row][col] == 0) {
				lab[row][col] = 1;
				ans = max(solve(lab, row, col,cnt + 1), ans);
				lab[row][col] = 0;
			}
		}
	}
	return ans;
}

int BFS(vector<vector<int>>& lab) {
	int** cpy = new int* [lab.size()];
	queue<pair<int, int>> q;
	pair<int, int> point;
	int dir[][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} }, row, col;
	for (row = 0; row < lab.size(); row++) {
		cpy[row] = new int[lab[0].size()];
		for (col = 0; col < lab[0].size(); col++) {
			cpy[row][col] = lab[row][col];
			if (cpy[row][col] == 2) {
				point.first = row;
				point.second = col;
				q.push(point);
			}
		}
	}
	while (!q.empty()) {
		point = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = point.first + dir[i][0];
			int nx = point.second + dir[i][1];
			if (ny > -1 && ny<lab.size() && nx>-1 && nx < lab[0].size()) {
				if (cpy[ny][nx] == 0) {
					cpy[ny][nx] = 2;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	int area=0;
	for (row = 0; row < lab.size(); row++) {
		for (col = 0; col < lab[0].size(); col++) {
			if (!cpy[row][col]) {
				area++;
			}
		}
		delete[] cpy[row];
	}
	delete[] cpy;
	return area;
}
