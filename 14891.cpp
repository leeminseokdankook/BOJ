#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void solve(string* Gears, int gear, int dir);
void left(string* Gears, int gear, int dir);
void right(string* Gear, int gear, int dir);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string Gears[5];
	vector<bool> visited({ false, false, false, false, false });
	int gear, k, dir, score = 0, score_table[5] = { 0,1,2,4,8 };
	for (int i = 1; i <= 4; i++) {
		cin >> Gears[i];
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> gear >> dir;
		solve(Gears, gear, dir);
	}
	for (int i = 1; i <= 4; i++) {
		score += (Gears[i][0] - '0') * score_table[i];
	}
	cout << score;
	return 0;
}

void solve(string* Gears, int gear, int dir) {
	left(Gears, gear-1, -dir);
	right(Gears, gear+1, -dir);
	if (dir == 1) {
		Gears[gear] = Gears[gear].substr(7,1) + Gears[gear].substr(0, 7);
	}
	else {
		Gears[gear] = Gears[gear].substr(1, 7) + Gears[gear].substr(0,1);
	}
}

void left(string* Gears, int gear, int dir) {
	if (gear< 1) {
		return;
	}
	if (Gears[gear][2] != Gears[gear+1][6]) {
		left(Gears, gear-1, -dir);
		if (dir == 1) {
			Gears[gear] = Gears[gear].substr(7, 1) + Gears[gear].substr(0, 7);
		}
		else {
			Gears[gear] = Gears[gear].substr(1, 7) + Gears[gear].substr(0, 1);
		}
	}
}
void right(string* Gears, int gear, int dir) {
	if (gear>4) {
		return;
	}
	if (Gears[gear][6] != Gears[gear-1][2]) {
		right(Gears, gear +1, -dir);
		if (dir == 1) {
			Gears[gear] = Gears[gear].substr(7, 1) + Gears[gear].substr(0, 7);
		}
		else {
			Gears[gear] = Gears[gear].substr(1, 7) + Gears[gear].substr(0, 1);
		}
	}
}
