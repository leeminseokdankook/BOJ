#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int cnt[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<int>> map;
	int r, c,k, time = 0,row,col;
	map.resize(100, vector<int>(100, 0));
	cin >> r >> c>>k;
	r--; c--;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			cin >> map[row][col];
		}
	}
	row = col = 3;
	while (1) {
		if (map[r][c] == k) {
			cout << time << '\n';
			return 0;
		}
		if (time == 100) {
			cout << -1 << '\n';
			return 0;
		}
		if (row >= col) {
			int max_col = -1;
			for (int i = 0; i < row; i++) {
				int index=0;
				vector<pair<int, int>> v;
				memset(cnt, 0, sizeof(cnt));
				for (int j = 0; j < col; j++) {
					cnt[map[i][j]]++;
					map[i][j] = 0;
				}
				for (int n = 1; n <= 100; n++) {
					if (cnt[n] == 0)continue;
					v.push_back({ cnt[n],n});
				}
				sort(v.begin(), v.end());
				for (auto iter = v.begin(); iter != v.end(); iter++) {
					map[i][index++] = iter->second;
					map[i][index++] = iter->first;
				}
				max_col = max(index, max_col);
			}
			col = max_col;
		}
		else {
			int max_row = -1;
			for (int i = 0; i < col; i++) {
				int index = 0;
				vector<pair<int, int>> v;
				memset(cnt, 0, sizeof(cnt));
				for (int j = 0; j < row; j++) {
					cnt[map[j][i]]++;
					map[j][i] = 0;
				}
				for (int n = 1; n <= 100; n++) {
					if (cnt[n] == 0)continue;
					v.push_back({ cnt[n],n });
				}
				sort(v.begin(), v.end());
				for (auto iter = v.begin(); iter != v.end(); iter++) {
					map[index++][i] = iter->second;
					map[index++][i] = iter->first;

				}
				max_row = max(index, max_row);
			}
			row = max_row;
		}
		time++;
	}
	return 0;
}
