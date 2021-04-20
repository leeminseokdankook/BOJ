#include <iostream>
using namespace std;

int main() {
	int* dp = 0;
	int n;
	cin >> n;
	dp = new int[n+1];
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3] + 1) {
				dp[i] = dp[i / 3] + 1;
			}
		}
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2] + 1) {
				dp[i] = dp[i / 2] + 1;
			}
		}
	}
	cout << dp[n];
	delete[] dp;
	return 0;
}
