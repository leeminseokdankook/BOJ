#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int* test;
	int N, B, C;
	long long int ans = 0;
	cin >> N;
	test = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> test[i];
	}
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		test[i] -= B;
		ans++;
		if (test[i] > 0) {
			ans += (test[i] / C) + (test[i] % C ? 1 : 0);
		}
	}
	cout << ans;
	return 0;
}
