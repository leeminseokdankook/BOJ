#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>
using namespace std;

int solve(vector<int>& sum, int pivot, int n, vector<int>& answer, int s)
{
	//return pivot-k
	//pivot을 기준으로 k개만큼 왼쪽 오른 쪽
	int l = 0, r = min(pivot, n - pivot), ans = 0;
	while (l <= r)
	{
		int k = (l + r) >> 1;
		int front_sum = sum[pivot] - sum[pivot - k];
		int back_sum = sum[pivot + k] - sum[pivot];
		if (front_sum > s || back_sum > s)
		{
			r = k - 1;
		}
		else
		{
			l = k + 1;
			ans = max(ans, k);
		}
	}
	answer[pivot - ans] = max(answer[pivot - ans], ans * 2);
	return pivot - ans;
}
int main()
{
	int n, s, len;
	vector<int> arr,sum,ans;
	map<int, int> m;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n>>s;
	arr.resize(n+1);
	sum.resize(n + 1);
	ans.resize(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		sum[i] = arr[i] + sum[i - 1];
	}
	for (int pivot = 1; pivot < n; ++pivot)
	{
		int start = solve(sum, pivot, n, ans, s);
		m[start] = max(m[start], ans[start]);
        //start 지점에서 가장 긴 2*k 부분 연속 수열
	}
	auto iter = begin(m);
	len = iter->second;
	for (int i = 0; i < n; ++i)
	{
		if (iter == end(m))
		{
			cout << (max(len-2, 0)) << "\n";
			len -= 2;
		}
		else
		{
			len = max(len - 2, 0);
            //현재 수열의 길이는 이전 수열의 길이-2
			if (i == iter->first)
			{
				len = max(iter->second, len);
                //새로운 수열이 나오면 길이 갱신
				++iter;
			}
			cout << len << "\n";
		}
	}
	return 0;
}
