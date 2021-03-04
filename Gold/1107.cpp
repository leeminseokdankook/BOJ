#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int num_press(vector<bool>& broken, int num);//if can make num, return press num count, else return 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int ans, N, M;
	vector<bool> broken;
	broken.resize(10, false);
	cin >> N>>M;
	while (M--) {
		int b;
		cin >> b;
		broken[b] = true;
	}
	ans = abs(N - 100);
	for (int i = 0; i <= 1000000; i++) {
		int num_cnt = num_press(broken,i);
		if (num_cnt) {
			int press_side = abs(i - N);
			ans = min(ans, press_side + num_cnt);
		}
	}
	cout << ans;
	return 0;
}

int num_press(vector<bool>& broken, int num) {
	if (num == 0) {
		if (broken[0]) return 0;
		else return 1;
	}
	int len = 0;
	while (num) {
		if (broken[num % 10])return 0;
		len += 1;
		num /= 10;
	}
	return len;
}