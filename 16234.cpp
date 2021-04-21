#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dir[][2] = { {1,0}, {-1,0}, {0,-1}, {0,1} };
void BFS(vector<vector<bool>>& visited, vector<vector<int>>& map, int pre_y, int pre_x, int l, int r);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, l, r, cnt = 0, ans=0;
	vector<vector<int>> map;
	vector<vector<bool>> visited;
	cin >> n>>l>>r;
	map.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		map[i].resize(n);
		visited[i].resize(n, false);
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	while (1) {
		int row, col, cnt=0;
		for (row = 0; row < n; row++) {
			for (col = 0; col < n; col++) {
				if (visited[row][col]) continue;
				visited[row][col] = true;
				BFS(visited, map, row, col, l, r);
				cnt++;
			}
		}
		if (n * n == cnt) {
			break;
		}
		for (row = 0; row < n; row++) {
			for (col = 0; col < n; col++) {
				visited[row][col] = false;
			}
		}
		ans++;
	}
	cout << ans;
	return 0;
}

void BFS(vector<vector<bool>>& visited, vector<vector<int>>& map, int pre_y, int pre_x, int l, int r) {
	queue<pair<int, int>> q, track;
	int sum = 0, n=0;
	q.push(make_pair(pre_y, pre_x));
	track.push(make_pair(pre_y, pre_x));
	while (!q.empty()) {
		pair<int, int > p = q.front(); q.pop();
		sum += map[p.first][p.second];
		n++;
		for (int i = 0; i < 4; i++) {
			int ny = p.first + dir[i][0], nx = p.second + dir[i][1];
			if (ny > -1 && ny < map.size() && nx<map.size() && nx>-1&&!visited[ny][nx]) {
				int diff = abs(map[p.first][p.second] - map[ny][nx]);
				if (diff >= l && diff <= r) {
					visited[ny][nx] = true;
					q.push(make_pair(ny, nx));
					track.push(make_pair(ny, nx));
				}
			}
		}
	}
	sum /= n;
	while (!track.empty()) {
		pair<int, int > p = track.front(); track.pop();
		map[p.first][p.second] = sum;
	}
}
