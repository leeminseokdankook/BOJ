#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool is_not_prime[10001] = {false};
	for (int i = 2; i <= 100; i++) {
		if (is_not_prime[i]) continue;
		for (int j = i * 2; j <= 10000; j += i) {
			is_not_prime[j] = true;
		}
	}
	int T, n;
	cin >> T;
	while (T > 0) {
		cin >> n;
		for (int i = n/2; 1; i--) {
			if (!is_not_prime[n - i] && !is_not_prime[i]) {
				cout << i << " " << n - i << "\n";
				break;
			}
		}
		T--;
	}
	return 0;
}


