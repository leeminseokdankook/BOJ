#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dir[][2] = { {1,0}, {-1,0}, {0,-1}, {0,1}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };

void Spring_and_Summer(vector<vector<vector<int>>>& woods, vector<vector<int>>& energy, int n);
void Fall(vector<vector<vector<int>>>& woods, int n);
void Winter(vector<vector<int>>& energy, vector<vector<int>>& insert, int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k,ans=0;
	vector<vector<vector<int>>> woods;
	vector<vector<int>> energy;
	vector<vector<int>> insert;
	cin >> n>>m>>k;
	woods.resize(n+1);
	energy.resize(n+1);
	insert.resize(n+1);
	for (int i = 1; i <= n; i++) {
		woods[i].resize(n+1);
		energy[i].resize(n+1,5);
		insert[i].resize(n+1);
		for (int j = 1; j <= n; j++) {
			cin >> insert[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int y, x, age;
		cin >> y >> x >> age;
		woods[y][x].push_back(age);
	}
	for (int i = 0; i < k; i++) {
		Spring_and_Summer(woods, energy,n);
		Fall(woods,n);
		Winter(energy, insert ,n);
	}
	for (vector<vector<int>>& row : woods) {
		for (vector<int>& col : row) {
			ans += col.size();
		}
	}
	cout << ans;
	return 0;
}

void Spring_and_Summer(vector<vector<vector<int>>>& woods, vector<vector<int>>& energy, int n) {
	//Spring
	int row, col;
	for (row = 1; row <= n; row++) {
		for (col = 1; col <= n; col++) {
			if (woods[row][col].empty()) continue;
			int die = 0,k;
			sort(woods[row][col].begin(), woods[row][col].end());
			for (k = 0; k < woods[row][col].size(); k++) {
				int mem = energy[row][col] - woods[row][col][k];
				if (mem < 0) {
					break;
				}
				energy[row][col] = mem;
				woods[row][col][k]++;
			}
			//Summer
			for (vector<int>::iterator iter = woods[row][col].begin() + k; iter != woods[row][col].end(); iter++) {
				die += *iter / 2;
			}
			woods[row][col].erase(woods[row][col].begin() + k, woods[row][col].end());
			energy[row][col] += die;
		}
	}
}

void Fall(vector<vector<vector<int>>>& woods, int n) {
	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= n; col++) {
			if (woods[row][col].empty()) continue;
			for (int age : woods[row][col]) {
				if (!(age % 5)) {
					for (int i = 0; i < 8; i++) {
						int ny = row + dir[i][1], nx = col + dir[i][0];
						if (ny > 0 && ny <= n && nx > 0 && nx <= n) {
							woods[ny][nx].push_back(1);
						}
					}
				}
			}
		}
	}
}

void Winter(vector<vector<int>>& energy, vector<vector<int>>& insert, int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			energy[i][j] += insert[i][j];
		}
	}
}
