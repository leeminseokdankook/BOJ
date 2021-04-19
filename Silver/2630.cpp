#include <iostream>
using namespace std;

int map[128][128];
int ans[2] = { 0 };
void Solve(int sy, int sx, int n);
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	Solve(0, 0, n);
	cout << ans[0] << '\n' << ans[1];
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
		Solve(sy, sx, n / 2);
		Solve(sy, sx + n / 2, n / 2);
		Solve(sy + n / 2, sx, n / 2);
		Solve(sy + n / 2, sx + n / 2, n / 2);
	}
	else {
		ans[x]++;
	}
}
