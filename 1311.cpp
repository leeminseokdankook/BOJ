#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int solve(int finished_mask, vector<int>& cost_memo, int finished_work_count,
	vector<vector<int>>& cost, int n);
int main()
{
	vector<int> memo;
	vector<vector<int>> cost;
	int n;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	cost.resize(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> cost[i][j];
		}
	}
	memo.resize(1 << n, -1);
	cout << solve(0, memo, 0, cost, n);
	return 0;
}

int solve(int finished_mask, vector<int>& cost_memo, int finished_work_count,
	vector<vector<int>>& cost, int n)
{
	int& ref = cost_memo[finished_mask];
	if (ref != -1)
	{
		return ref;
	}
	if (finished_work_count == n)
	{
		return ref=0;
	}
	ref = numeric_limits<int>::max();
	for (int i = 0; i < n; ++i)
	{
		if ((finished_mask & (1 << i))!=0) continue;
		ref = min(ref, cost[finished_work_count][i] + 
			solve(finished_mask | (1 << i), cost_memo, finished_work_count + 1, cost, n));
	}
	return ref;
}
