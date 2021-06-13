#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
using ll = long long;

ll solution(int n);
void dfs(int now, int previous, vector<vector<pair<int, int>>>& weight_graph, vector<int>& child, vector<ll>& cost);
void dfs(int now, int previous, vector<vector<pair<int, int>>>& weight_graph, vector<int>& child, vector<ll>& cost, ll total,int n, ll& ans);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		ll output = solution(n);
		cout << output << "\n";
	}
	return 0;
}

void dfs(int now, int previous, vector<vector<pair<int, int>>>& weight_graph, vector<int>& child, vector<ll>& cost) {
	child[now] = 1;
	for (auto& edge : weight_graph[now]) {
		if (edge.first == previous)continue;
		dfs(edge.first, now, weight_graph, child, cost);
		child[now] += child[edge.first];
		cost[now] += (static_cast<ll>(child[edge.first] * edge.second) + cost[edge.first]);
	}
}

void dfs(int now, int previous, vector<vector<pair<int, int>>>& weight_graph, vector<int>& child, vector<ll>& cost, ll total, int n,ll& ans) {
	ans = min(ans, total);
	for (auto& edge : weight_graph[now]) {
		int next = edge.first;
		int weight = edge.second;
		if (next == previous)
			continue;
		dfs(next, now, weight_graph, child, cost,total-(weight* child[next])+(n- child[next])*weight,n,ans);
	}
}

ll solution(int n) {
	vector<vector<pair<int, int>>> weight_graph(n);
	vector<int> child_cnt(n);
	vector<ll> cost_sum(n);
	ll ans;
	for (int i = 1; i < n; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		weight_graph[a].push_back({ b,w });
		weight_graph[b].push_back({ a,w });
	}
	dfs(0, 0, weight_graph, child_cnt, cost_sum);
	ans = numeric_limits<ll>::max();
	dfs(0, 0, weight_graph, child_cnt, cost_sum, cost_sum[0], n, ans);
	return ans;
}
