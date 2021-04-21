#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int* dp, N;
	pair<int, int> data;//data.first=T, data.second, pay;
	vector<pair<int, int>> schedule;
	cin >> N;
	dp = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> data.first >> data.second;
		schedule.push_back(data);
		dp[i] = data.second;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (i - j >= schedule[j].first) {
				dp[i] = max(dp[i], dp[j] + schedule[i].second);
			}
		}
	}
	int ans=0;
	for (int i = 0; i < N; i++) {
		if (i + schedule[i].first <= N) {
			ans = max(ans, dp[i]);
		}
	}
	cout << ans;
	delete[] dp;
	return 0;
}

