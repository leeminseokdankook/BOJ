#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ResultCompare(pair<string, int>& p1, pair<string, int>& p2)
{
	if (p1.second != p2.second)
	{
		return p1.second > p2.second;
	}
	else
	{
		if (p1.first.size() != p2.first.size())
		{
			return p1.first.size() > p2.first.size();
		}
		else
		{
			return p1.first < p2.first;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	vector<string> inputes;
	vector<pair<string, int>> result;
	cin >> n>>m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		inputes.push_back(str);
	}
	sort(begin(inputes), end(inputes));
	for (auto iter = begin(inputes); iter != end(inputes);)
	{
		string str = *iter;
		int cnt = 0;
		while (iter!=end(inputes)&&str == *iter)
		{
			++cnt;
			++iter;
		}
		if (str.size() < m)continue;
		else result.push_back({ str, cnt });
	}
	sort(begin(result), end(result), ResultCompare);
	for (auto& p : result)
	{
		cout << p.first << "\n";
	}
	return 0;
}
