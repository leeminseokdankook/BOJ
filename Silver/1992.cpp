#include <iostream>
using namespace std;

char map[65][65];

void Solve(int sy, int sx, int n);
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	Solve(0, 0, n);
	return 0;
}

void Solve(int sy, int sx, int n) {
	char x = map[sy][sx];
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
		cout << '(';
		Solve(sy, sx, n / 2);
		Solve(sy, sx + n / 2, n / 2);
		Solve(sy + n / 2, sx, n / 2);
		Solve(sy + n / 2, sx + n / 2, n / 2);
		cout << ')';
	}
	else {
		cout << x;
	}
}
