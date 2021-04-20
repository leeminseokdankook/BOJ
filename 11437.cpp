#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

int main() {
	vector<list<int>> tree;
	vector<int> parent;
	vector<int> depth;
	int n, m;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	parent.resize(n+1,0);
	depth.resize(n + 1,0);
	tree.resize(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	parent[1] = 1;
	depth[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int from = q.front();
		q.pop();
		for (auto to : tree[from]) {
			if (parent[to] == 0) {
				parent[to] = from;
				depth[to] = depth[from] + 1;
				q.push(to);
			}
		}
	}
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		//y가 언제나 더 깊은 곳
		if (depth[y] < depth[x]) {
			swap(x, y);
		}
		while (depth[y] != depth[x]) {
			y = parent[y];
		}
        if(x==y){
            cout<<x<<'\n';
        }
        else{
		    while (parent[y]!=parent[x])
		    {
			    y = parent[y];
			    x = parent[x];
		    }
		    cout <<parent[y] << '\n';
        }
	}
	return 0;
}
