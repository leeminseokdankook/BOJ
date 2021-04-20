#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt = 0;
	int N, n;
	cin >> N;
	while (N > 0) {
		cin >> n;
		if (is_prime(n)) {
			cnt++;
		}
		N--;
	}
	cout << cnt;
	return 0;
}

bool is_prime(int n) {
	if (n == 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (!(n % i)) return false;
	}
	return true;
}
