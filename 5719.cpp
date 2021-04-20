#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

/*
백준 5719

다익스트라 알고리즘 2번
(수행 할때 마다 지나간 간선을 표시)

visited[a][b]= a->b로 가는 간선을 이용하였는가

*/
int Solve(vector<list<pair<int, int>>>& cost, vector<vector<bool>>& visited, int start, int end);   //다익스트라 알고리즘 수행 후, 거리 반환
void DeleteEdge(vector<vector<bool>>& visited, vector<list<int>>& trace, int s, int e);   //간선 제거
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    while (1)
    {
        vector<list<pair<int, int>>> graph;
        vector<vector<bool>> visited;
        int s, e, now;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cin >> s >> e;
        graph.resize(n);
        while (m--)
        {
            int u, v, p;
            cin >> u >> v >> p;
            graph[u].push_back({ v,p });
        }
        visited.resize(n, vector<bool>(n, false));
        Solve(graph, visited, s, e);
        now = Solve(graph, visited, s, e);
        cout << now << '\n';
    }
    return 0;
}

int Solve(vector<list<pair<int, int>>>& cost, vector<vector<bool>>& visited, int start, int end)
{
    vector<int> distance(cost.size(), INT32_MAX);
    vector<list<int>> trace(cost.size(), list<int>());
    //trace[destination]=source list
    priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;  //cost ,vertex
    pq.push({ 0, start });
    distance[start] = 0;
    while (pq.empty() == false)
    {
 
        int v = pq.top().second;
        int c = pq.top().first;
        pq.pop();
        if (distance[v] < c)continue;   //현재 경로가 최단 경로가 아니면 스킵
        for (auto& p : cost[v])
        {
            int next_v = p.first;
            int next_c = p.second;
            int dis = c + next_c;
            if (visited[v][next_v]==false) //방문한 간선이 아니며
            {
                if (distance[next_v] > dis) //갱신이 필요할 때
                {
                    list<int> emp;
                    trace[next_v].swap(emp);
                    trace[next_v].push_back(v);
                    distance[next_v] = dis;
                    pq.push({ dis, next_v });
                }
                else if (distance[next_v] == dis)
                {
                    trace[next_v].push_back(v);
                }
            }
        }
    }
    DeleteEdge(visited, trace, start, end);
    int ret = distance[end];
    return ret == INT32_MAX ? -1 : ret;
}

void DeleteEdge(vector<vector<bool>>& visited, vector<list<int>>& trace, int s, int e)
{
    queue<int> q;
    q.push(e);
    while (!q.empty())
    {
        int dest = q.front();
        q.pop();
        for (auto source : trace[dest])
        {
            if (visited[source][dest])continue;
            visited[source][dest] = true;
            q.push(source);
        }
    }
}
