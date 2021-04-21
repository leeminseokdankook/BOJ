#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

int dir[][2] = { {0,-1}, {1,0}, {0,1},{-1,0} };
int solve(vector<vector<int>>& area, int r, int c, int d);
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	vector<vector<int>> area;
	int N, M,r,c,d;
	cin >> N >> M;
	cin >> r >> c >> d;
	area.resize(N);
	for (int row = 0; row < N; row++) {
		area[row].resize(M);
		for (int col = 0; col < M; col++) {
			cin >> area[row][col];
		}
	}
	int ans=solve(area, r,c,d);
	cout << ans;
	return 0;
}

int solve(vector<vector<int>>& area, int r, int c, int d) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {r,c},d });
	int ret = 0;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int direction = q.front().second;
		if (area[y][x] == 0) {
			area[y][x] = 2;
			ret++;
		}
		q.pop();
		int pre_d, ny, nx, cnt=0;
		bool flag=true;
		for (int i = 3; i > -1;i--) {
			pre_d = (direction + i) % 4;
			ny = y + dir[pre_d][1]; nx = x + dir[pre_d][0];
			if (ny > -1 && ny<area.size() && nx>-1 && nx < area[0].size()) {
				if (!area[ny][nx]) {
					q.push({ {ny,nx}, pre_d });
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			ny = y - dir[direction][1]; nx = x - dir[direction][0];
			if (ny > -1 && ny<area.size() && nx>-1 && nx < area[0].size()&& area[ny][nx] != 1) {
					q.push({ {ny,nx}, direction });
			}
			else {
				break;
			}
		}
	}
	return ret;
}



