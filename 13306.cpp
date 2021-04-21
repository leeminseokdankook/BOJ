#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int find(int u, vector<int>& tree) {
	if (tree[u] == u) {
		return u;
	}
	return tree[u] = find(tree[u], tree);
}

void Merge(int u, int v, vector<int>& tree, vector<int>& height) {
	//v는 u의 부모
	u = find(u, tree);
	v = find(v, tree);
	if (u == v)return;
	tree[u] = v;
}
int main() {
	vector<int> tree;
	vector<int> tree_2;
	vector<int> height;	//각 정점이 속한 트리의 높이
	int n, q;
	ios::sync_with_stdio(false);	
	cin.tie(0);
	cin >> n>>q;
	tree.resize(n + 1);
	tree_2.resize(n + 1);
	height.resize(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		tree_2[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		cin >> tree[i];
	}
	stack<pair<int,pair<int, int>>> st;
	stack<string> answer;
	int cnt = n - 1 + q;
	while (cnt--) {
		int x;
		cin >> x;
		if (x == 1) {
			int c, d;
			cin >> c >> d;
			st.push({ x,{c,d} });
		}
		else {
			int b;
			cin >> b;
			st.push({ x,{b,0} });
		}
	}
	while (!st.empty())
	{
		auto qu = st.top(); st.pop();
		if (qu.first == 1) {//연결 여부
			answer.push(find(qu.second.first, tree_2) == find(qu.second.second, tree_2) ? "YES\n" : "NO\n");
		}
		else {
			Merge(qu.second.first, tree[qu.second.first],tree_2,height);
		}
	}
	while (!answer.empty()) {
		cout << answer.top();
		answer.pop();
	}
	return 0;
}
