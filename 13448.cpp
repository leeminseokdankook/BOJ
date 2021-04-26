#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

typedef struct _INFO
{
	ll m, p, r;
	bool operator<(struct _INFO& rhs)
	{
		return this->r * rhs.p < this->p * rhs.r;
	}
}INFO;

ll solve(vector<INFO>& info_vector, int index, int t, vector<vector<ll>>& dp, int dead_time);
int main()
{
	vector<INFO> info_vector;
	vector<vector<ll>> dp;
	int n, dead_time;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> dead_time;
	dp.resize(n, vector<ll>(dead_time + 1, -1LL));
	info_vector.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> info_vector[i].m;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> info_vector[i].p;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> info_vector[i].r;
	}
	sort(begin(info_vector), end(info_vector));
	cout << solve(info_vector, 0, 0, dp, dead_time);
	return 0;
}

ll solve(vector<INFO>& info_vector, int index, int t, vector<vector<ll>>& dp, int dead_time)
{
	//index번 문제를 시간 t때 풀때
	if (index == info_vector.size())
	{
		return 0;
	}
	ll& ref = dp[index][t];
	//dp[index][t] -> index번째 문제룰 t분때 풀려고 했을때 얻을 수 있는 최고 점
	if (ref != -1)
	{
		return ref;
	}
	//초기 상태 -> 아예 안품
	ref = 0;
	ref = max(ref, solve(info_vector, index + 1, t, dp, dead_time));	//다음 문제로 넘어감
	if (info_vector[index].r + t <= dead_time)
	{
		//index번째 문제를 풀어서 맞출 수 있다면
		ref = max(ref, info_vector[index].m - (t + info_vector[index].r) * info_vector[index].p
			+ solve(info_vector, index + 1, t + info_vector[index].r, dp, dead_time));
	}
	return ref;
}
