#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
long long gcd(long long l, long long s);
long long Solve(vector<pair<int, int>>& v, vector<vector<long long>>& dp, int combine, int val, vector<int>& digites);
int main() 
{
	vector<int> digites;
	vector<string> stres;
	vector<pair<int, int>> v;
	int total_len = 0;
	long long p=0LL, q=1LL;
	vector<vector<long long>> dp;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	stres.resize(n);
	v.resize(n);
	for (int i = 1;i <= n; i++)
	{
		q *= i;
		cin >> stres[i-1];
	}
	cin >> k;
	dp.resize(1 << n, vector<long long>(k,-1));
	int index = 0;
	for (auto& str : stres)
	{
		int val = 0;
		total_len += str.length();
		for (auto ch : str)
		{
			val *= 10; val %= k;
			val += (ch - '0'); val %= k;
		}
		v[index++] = { val, str.length() };
	}
	digites.resize(total_len+1);
    //각 자릿수별로 나머지 계산
	digites[0] = 1 % k;
	for (int i = 1; i <= total_len; i++)
	{
		digites[i] = digites[i - 1] * 10 % k;
	}
	p = Solve(v, dp, 0, 0, digites);
	if (p == 0)
	{
		cout << "0/1";
	}
	else
	{
		long long g = gcd(max(p,q), min(p,q));
		cout << p / g << "/" << q / g ;
	}

	return 0;
}

long long gcd(long long l, long long s)
{
	return s ? gcd(s, l % s) : l;
}

long long Solve(vector<pair<int, int>>& v, vector<vector<long long>>& dp, int combine, int val, vector<int>& digites)
{
	long long& ret = dp[combine][val];
	if (ret != -1LL)
	{
		return ret;
	}
	if (combine + 1 == (1 << n))
	{
		if (val)
		{
			return ret = 0LL;
		}
		else
		{
			return ret = 1LL;
		}
	}
	ret = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if ((combine & (1 << i))==0)
		{
			int temp= digites[v[i].second] * val + v[i].first;
			ret += Solve(v, dp, combine | (1 << i), temp % k, digites);
		}
	}
	return ret;
}