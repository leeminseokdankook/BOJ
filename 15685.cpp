#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solve(int max_g, vector<pair<pair<int, int>, pair<int ,int>>>&);
bool is_end(vector<vector<bool>>& is_connect);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<pair<int, int>, pair<int, int>>> curve;
	pair<pair<int, int>, pair<int, int>> data;
	int N, max_g=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> data.first.second >> data.first.first >> data.second.first >> data.second.second;
		max_g = max(max_g, data.second.second);
		curve.push_back(data);
	}
	cout << solve(max_g, curve);
	return 0;
}

int solve(int max_g, vector<pair<pair<int, int>, pair<int, int>>>& data){
	bool map[101][101] = { false, };
	int dir_count = pow(2, max_g);
	int* curve_dir[4];
	curve_dir[0]=new int[dir_count];
	curve_dir[1] = new int[dir_count];
	curve_dir[2] = new int[dir_count];
	curve_dir[3] = new int[dir_count];
	curve_dir[0][0] = 0;
	curve_dir[1][0] = 1;
	curve_dir[2][0] = 2;
	curve_dir[3][0] = 3;
	for (int k = 0; k < 4; k++) {
		for (int i = 1; i <= max_g; i++) {
			int start = pow(2, i - 1);
			int end = pow(2, i);
			for (int pre = start, cnt = 1; pre < end; pre++, cnt+=2) {
				curve_dir[k][pre] = curve_dir[k][pre - cnt] + 1 == 4 ? 0 : curve_dir[k][pre - cnt] + 1;
			}
		}
	}
	for (pair<pair<int, int>, pair<int, int>>& p : data) {
		int dy = p.first.first, dx = p.first.second, g=p.second.second, d=p.second.first;
		map[dy][dx] = true;
		for (int i = 0; i < pow(2, g); i++) {
			switch (curve_dir[d][i])
			{
				case 0:
					dx++;
					break;
				case 1:
					dy--;
					break;
				case 2:
					dx--;
					break;
				case 3:
					dy++;
					break;
			}
			map[dy][dx] = true;
		}
	}
	int cnt = 0;
	for (int row = 0; row < 100; row++) {
		for (int col = 0; col < 100; col++) {
			if (map[row][col] && map[row][col + 1] && map[row + 1][col] && map[row + 1][col + 1]) {
				cnt++;
			}
		}
	}
	delete[] curve_dir[0], curve_dir[1], curve_dir[2], curve_dir[3], curve_dir;
	return cnt;
}
