#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;


/*

Baekjoon 6416 트리인가?

입력 형식
u->v 로 가는 간선을 공백으로 구분하여 입력
ex) u1 v1 u2 v2 ....
0 0을 입력하면 간선 입력 종료
-1 -1을 입력하면 테스트 종료

출력 형식
0 0을 입력한 경우를 하나의 케이스로 확인
T번째 케이스가 트리 이면
Case T is a tree.\n
아니면
Case T is not a tree\n

트리의 조건

1. 들어오는 간선은 없고 나가는 간선만 존재한 노드 존재 , 이를 root라 지칭
2. root 노드를 제외한 노드엔 들어오는 간선이 하나만 존재
3. root에서 다른 노드로 가는 경우는 반드시 존재하고 유일, 이는 root를 제외한 모든 노드에 유효

*/


void Result(int Case, bool flag);		//출력

bool CheckTree(vector<list<int>>& graph ,list<pair<int, int>>& edges);	//root를 기준으로 트리인지 확인

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool flag = true;
	int T = 1;
	while (flag)
	{
		int max_n = 0;				//최고 정점 번호
		vector<list<int>> graph;
		list<pair<int, int>> edges;
		int u, v;
		while (true)
		{
			cin >> u >> v;
			if (u < 1 && v < 1)
			{
				break;
			}
			max_n = max(max_n, max(u,v));
			edges.push_back({ u, v });
		}
		if (u == -1 && v == -1)
		{
			flag = false;
		}
		else if (u == 0 && v == 0)
		{
			graph.resize(max_n + 1, list<int>());
			Result(T, CheckTree(graph, edges));
		}
		T++;
	}

	return 0;
}

void Result(int Case, bool flag)
{
	if (flag)
	{
		cout << "Case " << Case << " is a tree.\n";
	}
	else
	{
		cout << "Case " << Case << " is not a tree.\n";
	}
}

bool CheckTree(vector<list<int>>& graph, list<pair<int, int>>& edges)
{
    if (edges.size() == 0) return true;	//간선이 0개여도 트리임
	vector<int> out, in;
	vector<bool> visited;
	//in[i]는 i로 들어오는 간선의 수
	//out[i] 는 i에서 나가는 간선의 개수
	int root_cnt = 0;		//루트 노드의 개수
	int root=0, edge_cnt=0;				
	out.resize(graph.size());
	in.resize(graph.size());
	visited.resize(graph.size(), false);
	for (auto& edge : edges)
	{
		out[edge.first]++;
		in[edge.second]++;
		graph[edge.first].push_back(edge.second);
	}
	for (int i = 1; i < graph.size(); i++)
	{
		if (out[i] == 0 && in[i] == 0)continue;
		if (in[i] > 1)return false;				//들어오는 간선이 2개이상이면 트리가 아님
		if (out[i] > 0 && in[i] == 0)			//들어오는 간선이 없고 나가는 간선이 존재
		{
			root = i;
			root_cnt++;
		}
	}
	if (root_cnt != 1)		//root가 1개가 아니라면
	{
		return false;
	}

	//root를 기준으로 BFS 수행
	queue<int> q;
	q.push(root);
	visited[root] = true;
	while (!q.empty())
	{
		int node = q.front(); q.pop();
		for (auto& v : graph[node])
		{
			if (visited[v])		//트리면 사이클이 존재할 수 없음 -> BFS를 수행하면 각 노드를 한 번만 방문함
			{
				return false;
			}
			visited[v] = true;
			q.push(v);
			edge_cnt++;
		}
	}

	if (edge_cnt == edges.size())	//총 간선 수 == 입력한 간선이면 
	{
		return true;
	}
	else							//트리에 속하지 않는 간선이 존재
	{
		return false;
	}
}
