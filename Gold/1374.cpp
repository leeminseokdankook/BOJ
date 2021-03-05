#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> schedule;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	int room_cnt=0;
	int n;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		long long s, e;
		cin >> num >> s >> e;
		schedule.push({ s,e });
	}
	while (schedule.empty() == false)
	{
		auto temp = schedule.top();
        schedule.pop();
		if (pq.empty())
		{
			pq.push(temp.second);
		}
		else
		{
			if (pq.top() <= temp.first)
			{
				while (pq.empty()==false&&pq.top() <= temp.first)
				{
					pq.pop();
				}
			}
			pq.push(temp.second);
		}
		room_cnt = max(room_cnt, static_cast<int>(pq.size()));
	}
	cout << room_cnt;
	return 0;
}
