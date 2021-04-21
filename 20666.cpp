#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;
using ll=long long;

int main() {
	// your code goes here
	priority_queue<pair<ll, int>,vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	vector<ll> cost;
	bool* visited=0;
	int n,m,p;
	ll ans=(1LL<<(sizeof(ll)*8-1));
	vector<list<pair<int, ll>>> tips;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	visited=new bool[n+1];
	cost.resize(n+1);
	tips.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		visited[i]=false;
		cin>>cost[i];
	}
	cin>>p;
	while(p--)
	{
		int a,b;
		ll t;
		cin>>a>>b>>t;
		tips[a].push_back({b,t});
		cost[b]+=t;
	}
	for(int i=1;i<=n;i++)
	{
		pq.push({cost[i], i});
	}
	while(m--)
	{
		pair<ll, int> pick;
		do
		{
			pick=pq.top();
			pq.pop();
		}while(visited[pick.second]==true);
		visited[pick.second]=true;
		ans=max(ans, pick.first);
		for(auto& tip:tips[pick.second])
		{
			cost[tip.first]-=tip.second;
			pq.push({cost[tip.first], tip.first});
		}
	}
	cout<<ans;
	delete[] visited;
	return 0;
}
