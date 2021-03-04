#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, L, x=-1,l;
	cin >> N >> L;
	for (l = L; l <= 100; l++) {
		int t = l * (l - 1) / 2;
		if ((N - t)%l == 0 && (N - t) / l >= 0) {
			x = (N - t) / l;
			break;
		}
	}
	if (x == -1)cout << -1;
	else {
		for (int i = 0; i < l; i++) {
			cout << x + i << " ";
		}
	}
	return 0;
}
