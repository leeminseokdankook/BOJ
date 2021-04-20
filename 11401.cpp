#include <iostream>
#include <vector>
#define MOD 1000000007LL
using namespace std;

long long int solve(long long int b, long long int p) {
	if (p ==0LL) {
		return 1LL;
	}
	if (p & 1LL) {
		return b * solve(b, p - 1)%MOD;
	}
	long long int half = solve(b, p >> 1)%MOD;
	return half * half % MOD;
}
int main() {
	vector<long long int> dp;
	long long int n, k;
	cin >> n >> k;
	long long int a=1LL;
	long long int b=1LL;
	for (long long int i = n; i > n - k; i--) {
		a = a * i % MOD;
	}
	for (long long int i = 1; i <= k; i++) {
		b = b * i % MOD;
	}
	long long int b_p_2 = solve(b, MOD - 2LL);
	cout << a * b_p_2 % MOD;
	return 0;
}
