#include <iostream>
#include <algorithm>
using namespace std;

int Rev(int x);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int X, Y;
	cin >> X >> Y;
	cout << Rev(Rev(X) + Rev(Y));
	return 0;
}
int Rev(int x) {
	int ret = 0;
	while (x) {
		ret *= 10;
		ret += x % 10;
		x = x / 10;
	}
	return ret;
}
