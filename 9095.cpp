#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> dp;
	int T;
	cin >> T;
	dp.push_back(1);
	dp.push_back(1);
	dp.push_back(2);
	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);
		for (int k = dp.size() - 1; k < n; k++) {
			dp.push_back(dp[k] + dp[k - 1] + dp[k - 2]);
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
