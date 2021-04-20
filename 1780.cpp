#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
int ans[3] = { 0 };

void Solve(int sy, int sx, int n);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	map.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	Solve(0, 0, n);
	cout << ans[0] << '\n' << ans[1]<<'\n'<<ans[2];
	return 0;
}

void Solve(int sy, int sx, int n) {
	int x = map[sy][sx];
	bool flag=false;
	for (int i = sy; i < sy + n; i++) {
		for (int j = sx; j < sx + n; j++) {
			if (map[i][j] != x) {
				flag = true;
				break;
			}
		}
	}
	if (flag) {
		n = n / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				Solve(sy + n * i, sx + n * j, n);
			}
		}
	}
	else {
		ans[x+1]++;
	}
}
