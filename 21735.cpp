#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll ans=1;
void solve(vector<int>& arr, int m, int time, int prevent_index, ll size, int n);
int main()
{
	vector<int> arr;
	int n, m;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	arr.resize(n+1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}
	solve(arr, m, 0, 0,1,n);
	cout << ans;
	return 0;
}

void solve(vector<int>& arr, int m, int time, int prevent_index,ll size, int n)
{
	
	if (time == m)
	{
		ans = max(ans, size);
		return;
	}
	if (prevent_index == n)
	{
		ans = max(ans, size);
		return;
	}
	if(prevent_index+1<arr.size())
		solve(arr, m, time + 1, prevent_index + 1, size + arr[prevent_index + 1],n);
	if (prevent_index + 2 < arr.size())
	{	
		int half = size / 2;
		solve(arr, m, time + 1, prevent_index + 2, half+arr[prevent_index + 2],n);
	}
}
