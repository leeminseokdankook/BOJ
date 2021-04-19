#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b, c, val, cnt[10] = {0};
	cin >> a >> b >> c;
	val = a * b * c;
	int pre = val;
	while (pre) {
		cnt[pre % 10]++;
		pre /= 10;
	}
	for (int x : cnt) {
		cout << x << "\n";
	}
	return 0;
}

