#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;
/*
1. dfs로 트리를 구성

2. dfs로 hld 수행 및 번호 재구성

3. segment tree구성

4. 쿼리 수행

*/
int cnt = 1;
vector<int> top;
vector<int> candy;
vector<int> segment;
vector<int> mark;
vector<int> node_cnt;
vector<int> tree;	//tree[v] -> v의 부모 
vector<int> depth;	//level[v] -> v지점의 깊이
vector<int> new_candy;
vector<vector<int>> graph;

int DFS0(int pre, int now) {
	node_cnt[now] = 1;		//현재 노드의 개수 1
	depth[now] = depth[pre] + 1;	//깊이는 이전 노드의 깊이 +1
	tree[now] = pre;				//현재 노드의 부모노드 저장
	for(int i=0;i<graph[now].size();i++)
	{
		if (graph[now][i] == pre) continue;		
		node_cnt[now] += DFS0(now, graph[now][i]);	//각 서브 트리의 노드 개수 만큼 추가
		if (node_cnt[graph[now][i]] > node_cnt[graph[now][0]])	
		{
			swap(graph[now][i], graph[now][0]);
		}
	}
	return node_cnt[now];
}

void DFS1(int pre,int now) {
	new_candy[cnt] = candy[now];
	mark[now] = cnt++;
	for(int i=0;i<graph[now].size();i++)
	{
		if (graph[now][i] == pre)continue;
		top[graph[now][i]] = (i==0) ? top[now] : graph[now][i];
		DFS1(now, graph[now][i]);
	}
}

int MakeSegment(int l, int r, int index) {
	if (l == r)
	{
		return segment[index] = (1 << new_candy[l]);
	}
	int mid = (l + r) >> 1;
	int left = MakeSegment(l, mid, index << 1);
	int right = MakeSegment(mid + 1, r, (index << 1) | 1);
	segment[index] = left | right;
	return segment[index];
}

int find(int s, int e, int l, int r, int index) {
	//segment tree[index]의 범위는 [l~r]
	//구하고자 하는 범위는 [s~e]
	if (l>e||r<s)
	{
		return 0;
	}
	if (s<=l&&r<=e)
	{
		return segment[index];
	}
	int mid = (l + r) >> 1;
	int left = find(s, e, l, mid, index << 1);
	int right = find(s, e, mid + 1, r, (index << 1) | 1);
	int ret = left | right;
	return ret;
}

bool query(int start, int dest, int k) {
	int ans = 0, lca;
	int heavy=start, light=dest;	
	//light -> 낮은 번호
	//heavy -> 높은 번호
	while (1) 
	{
		if (mark[heavy] < mark[light])swap(heavy, light);
		if (top[heavy] == top[light])break;
		heavy = tree[top[heavy]];
		//높은 번호를 먼저 UP
		//낮은 번호 일수록 큰 서브 트리에 종속
	}
	lca = light;
	while (1) 
	{
		if (top[lca] == top[start])break;
		ans |= find(mark[top[start]], mark[start], 1, tree.size() - 1, 1);
		start = tree[top[start]];
	}
	ans |= find(mark[lca], mark[start], 1, tree.size() - 1, 1);
	while (1)
	{
		if (top[lca] == top[dest])break;
		ans |= find(mark[top[dest]], mark[dest], 1, tree.size() - 1, 1);
		dest = tree[top[dest]];
	}
	ans |= find(mark[lca], mark[dest], 1, tree.size() - 1, 1);
	if (ans & (1 << k))return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, v, u, position, M, height=1,i, has_candy=0;
	cin >> N;
	candy.resize(N + 1);
	mark.resize(N + 1);
	node_cnt.resize(N + 1);
	tree.resize(N + 1);
	depth.resize(N + 1);
	graph.resize(N + 1);
	top.resize(N + 1);
	new_candy.resize(N + 1);
	segment.resize(4 * N + 1);
	for (i = 1; i <= N; i++) 
	{
		cin >> candy[i];
		has_candy |= (1 << candy[i]);
	}
	for(i=1;i<N;i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	top[1] = 1;
	tree[1] = 1;
	DFS0(1, 1);
	DFS1(1,1);
	MakeSegment(1, N, 1);
	int c;
	cin >> M;
	M--;
	cin >> v >> c;
	if (has_candy & (1 << c)) 
	{
		cout << "PLAY\n";
	}
	else 
	{
		cout << "CRY\n";
	}
	while (M--) {
		position = v;
		cin >> v >> c;
		if (query(position,v,c))
		{
			cout << "PLAY\n";
		}
		else 
		{
			cout << "CRY\n";
		}
	}
	return 0;
}
