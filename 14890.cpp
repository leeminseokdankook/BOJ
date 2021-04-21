#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<vector<int>> load;
	int N, L, ans, row, col;
	cin >> N >> L;
	ans = N * 2;
	load.resize(N);
	for (int i = 0; i < N; i++) {
		load[i].resize(N);
		for (int j = 0; j < N; j++) {
			cin >> load[i][j];
		}
	}
	//가로줄 검사
	for (row = 0; row < N; row++) {
		int h = load[row][0], len=0;
		for (col = 0; col < N; col++) {
			if (h == load[row][col]) {
				len++;
				continue;
			}
			int diff=h - load[row][col];
			//내리막길
			if (diff== 1) {
				h = load[row][col];
				if (col + L-1>= N) {
					break;
				}
				else {
					for (len = 0; len < L; len++) {
						if (load[row][col+len] != h) {
							break;
						}
					}
					if (len != L ) {
						break;
					}
					if (col + L < N && load[row][col + L] > h) {
						break;
					}
					col = col + L-1;
					len = 0;
				}
			}
			//d오르막길
			else if(diff==-1){
				if (len < L) {
					break;
				}
				h = load[row][col];
				len = 1;
			}
			else {
				break;
			}
		}
		if (col != N) {
			ans--;
		}
	}
	//세로줄 검사;
	for(col = 0; col < N; col++) {
		int h = load[0][col], len = 0;
		for (row = 0; row < N; row++) {
			if (h == load[row][col]) {
				len++;
				continue;
			}
			int diff = h - load[row][col];
			if (diff == 1) {
				h = load[row][col];
				if (row + L-1 >= N) {
					break;
				}
				else {
					for (len = 0; len < L; len++) {
						if (load[row+len][col] != h) {
							break;
						}
					}
					if (len != L) {
						break;
					}
					if (row + L < N && load[row+L][col] >h) {
						break;
					}
					row = row + L-1;
					len = 0;
				}
			}
			else if (diff == -1) {
				if (len < L) {
					break;
				}
				h = load[row][col];
				len = 1;
			}
			else {
				break;
			}
		}
		if (row != N) {
			ans--;
		}
	}
	cout << ans;
	return 0;
}
