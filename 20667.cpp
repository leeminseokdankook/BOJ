#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
	int n, m, k;
	vector<vector<int>> dp(1001, vector<int>(501,-1));
	cin >> n >> m >> k;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		int pri, mem, c;
		cin >> c >> mem >> pri;
		for (int cpu = 1000; cpu >= c; --cpu)
		{
			for (int priority = 500; priority >= pri; --priority)
			{
				if (dp[cpu - c][priority - pri] == -1)continue;
				dp[cpu][priority] = max(dp[cpu][priority], dp[cpu - c][priority - pri] + mem);
			}
		}
	}
	int ans = INT32_MAX;
	for (int cpu = m; cpu <= 1000; cpu++)
	{
		for (int pri = 1; pri <= 500; pri++)
		{
			if (dp[cpu][pri] == -1)continue;
			else
			{
				if (dp[cpu][pri] >= k)
				{
					ans = min(ans, pri);
					break;
				}
			}
		}
	}
	if (ans == INT32_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
	return 0;
}
