#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void Solve(int start, int end, vector<int>& up, vector<int>& down, vector<int>& total, vector<int>* cost, int w);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		vector<int> up, down, total;
		vector<int> cost[2];
		int n, ans, w;
		cin >> n >> w;
		up.resize(n);
		down.resize(n);
		total.resize(n);
		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < n; i++)
			{
				int x;
				cin >> x;
				cost[j].push_back(x);
			}
		}
		Solve(0, n, up, down, total, cost, w);
		ans = total[n - 1];
		if (n > 1)
		{
			if ((cost[0][0] + cost[0][n - 1]) <= w)		//윗라인 묶기
			{
				int cost_0 = cost[0][0], cost_n = cost[0][n - 1];
				cost[0][0] = cost[0][n - 1] = w;
				Solve(0, n, up, down, total, cost, w);
				ans = min(ans, down[n - 1]);
				cost[0][0] = cost_0;
				cost[0][n - 1] = cost_n;
			}
			if (cost[1][0] + cost[1][n - 1] <= w)		//아랫라인 묶기
			{
				int cost_0 = cost[1][0], cost_n = cost[1][n - 1];
				cost[1][0] = cost[1][n - 1] = w;
				Solve(0, n, up, down, total, cost, w);
				ans = min(ans, up[n - 1]);
				cost[1][0] = cost_0;
				cost[1][n - 1] = cost_n;
			}
			if (cost[1][0] + cost[1][n - 1] <= w && cost[0][0] + cost[0][n - 1] <= w)		//둘다 묶기
			{
				int cost_1, cost_2, cost_3, cost_4;
				cost_1 = cost[0][0]; cost_2 = cost[1][0]; cost_3 = cost[0][n - 1]; cost_4 = cost[1][n - 1];
				cost[0][0] = cost[1][0] = cost[0][n - 1] = cost[1][n - 1] = w;
				Solve(0, n, up, down, total, cost, w);
				ans = min(ans, total[n - 2]);
			}
		}
		cout << ans<<'\n';
	}
	return 0;
}

void Solve(int start, int end, vector<int>& up, vector<int>& down, vector<int>& total, vector<int>* cost, int w) {
	if (cost[0][0] + cost[1][0] <= w) {
		total[0] = 1;
	}
	else {
		total[0] = 2;
	}
	up[0] = 1;
	down[0] = 1;
	for (int i = 1; i < end; i++) {
		up[i] = total[i - 1] + 1;
		down[i] = total[i - 1] + 1;
		total[i] = total[i-1]+2;
		//i열 윗지역 점렬
		if (cost[0][i] + cost[0][i - 1] <= w) {
			up[i] = min(up[i], down[i - 1] + 1);
		}
		//i열 아랫 지역 점령
		if (cost[1][i] + cost[1][i - 1] <= w) {
			down[i] = min(down[i], up[i - 1] + 1);
		}
		total[i] = min(total[i], up[i] + 1);
		total[i] = min(total[i], down[i] + 1);
		//i열 모두 점령
		if (cost[0][i] + cost[1][i] <= w) {
			total[i] = min(total[i], total[i - 1] + 1);
		}
		if (cost[0][i] + cost[0][i - 1] <= w && cost[1][i] + cost[1][i - 1] <= w)
		{
			if (i >= 2)
			{
				total[i] = min(total[i], total[i - 2] + 2);
			}
			else {
				total[i] = min(total[i], 2);
			}
		}

	}
}
