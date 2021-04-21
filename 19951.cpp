#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> heights;
	vector<int> diff;
	int n, m, h=0;
	cin >> n >> m;
	heights.resize(n+1);
	diff.resize(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> heights[i];
	}
	while (m--)
	{
		int a, b, h;
		cin >> a >> b >> h;
		diff[a] += h;
		diff[b+1] += -h;
	}
	for (int i = 1; i <= n; i++)
	{
		h += diff[i];
		cout << heights[i] + h << " ";
	}
	return 0;
}
