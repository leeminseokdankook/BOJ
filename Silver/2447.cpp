#include <iostream>
using namespace std;
char map[2188][2188];
void rec(int y, int x, int n) {
	if (n == 1) {
		map[y][x] = '*';
		return;
	}
	int div = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			rec(y + div * i, x + div * j, div);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = ' ';
		}
	}
	rec(1, 1, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	return 0;
}


