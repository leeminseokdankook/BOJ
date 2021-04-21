#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, X, K;
	cin >> N>>X>>K;
	while (K--) {
		int a, b;
		cin >> a >> b;
		if (a == X) {
			X = b;
		}
		else if (b == X) {
			X = a;
		}
	}
	cout << X;
	return 0;
}
