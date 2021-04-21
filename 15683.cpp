#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dir[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };//(dx,dy)
void detect(vector<vector<int>>& area, int y, int x, int dir_index);
void undo(vector<vector<int>>& area, int y, int x, int dir_index);
int solve(vector<vector<int>>& area, vector<pair<int, int>>& cctv_point, int index);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<vector<int>> area;
	int N,M;
	vector<pair<int, int>> cctv_point;
	cin >> N >> M;
	area.resize(N);
	for (int i = 0; i < N; i++) {
		area[i].resize(M);
		for (int j = 0; j < M; j++) {
			cin >> area[i][j];
			if (area[i][j] && area[i][j] != 6) {
				pair<int, int> data;
				data.first = i;
				data.second = j;
				cctv_point.push_back(data);
			}
		}
	}
	cout<< solve(area, cctv_point, 0);
	return 0;
}

int solve(vector<vector<int>>& area, vector<pair<int, int>>& cctv_point, int index) {
	int ans;
	if (cctv_point.size() == index) {
		ans = 0;
		for (vector<int>& l : area) {
			for (int x : l) {
				if (!x) {
					ans++;
				}
			}
		}
		return ans;
	}
	ans = INT32_MAX;
	int y = cctv_point[index].first, x = cctv_point[index].second;
	switch (area[y][x]){
		case 1:
			for (int i = 0; i < 4; i++) {
				detect(area, y, x, i);
				ans = min(ans, solve(area, cctv_point, index + 1));
				undo(area, y, x, i);
			}
			break;
		case 2:
			for (int i = 0; i < 2; i++) {
				detect(area, y, x, i);
				detect(area, y, x, i + 2);
				ans = min(ans, solve(area, cctv_point, index + 1));
				undo(area, y, x, i);
				undo(area, y, x, i + 2);
			}
			break;
		case 3:
			for (int i = 0; i < 4; i++) {
				detect(area, y, x, i);
				detect(area, y, x, (i + 1)%4);
				ans = min(ans, solve(area, cctv_point, index + 1));
				undo(area, y, x, i);
				undo(area, y, x, (i + 1)%4);
			}
			break;
		case 4:
			for (int i = 0; i < 4; i++) {
				detect(area, y, x, i);
				detect(area, y, x, (i + 1) % 4);
				detect(area, y, x, (i + 2) % 4);
				ans = min(ans, solve(area, cctv_point, index + 1));
				undo(area, y, x, i);
				undo(area, y, x, (i+1)%4);
				undo(area, y, x, (i + 2) % 4);
			}
			break;
		case 5:
			detect(area, y, x, 0);
			detect(area, y, x, 1);
			detect(area, y, x, 2);
			detect(area, y, x ,3);
			ans = min(ans, solve(area, cctv_point, index + 1));
			undo(area, y, x, 0);
			undo(area, y, x, 1);
			undo(area, y, x, 2);
			undo(area, y, x, 3);
			break;
	}
	return ans;
}

void detect(vector<vector<int>>& area, int y, int x, int dir_index) {
	int ny = y + dir[dir_index][1], nx = x + dir[dir_index][0];
	while ((ny > -1 && ny<area.size() && nx>-1 && nx < area[0].size()) && area[ny][nx] !=6) {
		if (area[ny][nx] <=0) {
			area[ny][nx]--;
		}
		ny += dir[dir_index][1];
		nx += dir[dir_index][0];
	}
}

void undo(vector<vector<int>>& area, int y, int x, int dir_index) {
	int ny = y + dir[dir_index][1], nx = x + dir[dir_index][0];
	while ((ny>-1&&ny<area.size()&&nx>-1&&nx<area[0].size())&&area[ny][nx] != 6) {
		if (area[ny][nx] <0) {
			area[ny][nx]++;
		}
		ny += dir[dir_index][1];
		nx += dir[dir_index][0];
	}
}
