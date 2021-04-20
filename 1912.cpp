#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> dp, data;
	int n, ans;
	cin >> n;
	data.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	ans=dp[0] = data[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + data[i], data[i]);
		ans = max(dp[i], ans);
	}
	printf("%d", ans);
	return 0;
}
