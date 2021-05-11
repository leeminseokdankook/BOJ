#include <vector>
#include <iostream>
using namespace std;
using ll = long long;

ll power(int n, ll k)
{
	if (k == 1)return n;
	if (k == 0)return 1;
	ll ret = power(n, k>>1)%1000000007LL;
	ret = ret * ret % 1000000007LL;
	if (k & 1)
	{
		ret = ret * (ll)n % 1000000007LL;
	}
	return ret;
}
int main()
{
	const ll MOD = 1000000007;
	int n;
	vector<ll> dp;
	cin >> n;
	if (n == 1)
	{
		cout << 1;
	}
	else if (n == 2)
	{
		cout << 2;
	}
	else
	{
		dp.resize(n + 1);
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 2; i < n; ++i)
		{
			dp[i + 1] = ((2 * (2LL * i + 1) * dp[i]%MOD) * power(i + 2, MOD - 2)%MOD)%MOD;
		}
		cout << dp[n];
	}
	return 0;
}
