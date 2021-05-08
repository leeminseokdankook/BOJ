#include <iostream>
#include <vector>
#include <limits>
#include <bitset>
#include <stack>
#include <queue>
using namespace std;

void Get_distance(vector<vector<int>>& graph, vector<int>& distance, int s);
int main()
{
    vector<vector<int>> graph;
    vector<int> distance;
    vector<pair<int, int>> edges;
    stack<pair<char, int>> queries;    //쿼리를 스택방식으로 처리
    stack<int> ans;                     //스택형식으로 처리한 쿼리의 출력을 다시 스택에 삽입
    bitset<100001> can_use;
    int n, m, q;
    bool changed = true;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    can_use.set();
    cin >> n >> m >> q;
    graph.resize(n + 1);
    distance.resize(n + 1,numeric_limits<int>::max());
    edges.resize(m + 1);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = { u,v };
    }
    //쿼리를 삽
    for (int i = 0; i < q; ++i)
    {
        char t;
        int p;
        cin >> t >> p;
        if (t == 'U')
        {
            //사용하지 않을 간선을 표시함
            can_use.set(p, false);
        }
        queries.push({ t,p });
    }
    //최종적으로 사용되지 않을 간선을 제외하고 그래프를 만듬
    for (int i = 1; i <= m; ++i)
    {
        if (can_use[i])
        {
            int u = edges[i].first;
            int v = edges[i].second;
            graph[u].push_back(v);
        }
    }
    //생성된 그래프를 통해 1번 정점부터 연결된 정점까지의 거리 확인
    distance[1]=0;
    Get_distance(graph, distance,1);
    while (queries.empty() == false)
    {
        auto query = queries.top(); queries.pop();
        char t = query.first;
        int p = query.second;
        if (t == 'U')
        {
            //제거되었던 간선을 연결후, 거리 갱신
            int u = edges[p].first;
            int v = edges[p].second;
            graph[u].push_back(v);
            changed = true;
            Get_distance(graph, distance,u);
        }
        else
        {
            if (distance[p] == numeric_limits<int>::max())
            {
                ans.push(-1);
            }
            else
            {
                ans.push(distance[p]);
            }
        }
    }
    while (ans.empty() == false)
    {
        cout << ans.top() << "\n";
        ans.pop();
    }
    return 0;
}

void Get_distance(vector<vector<int>>& graph, vector<int>& distance, int s)
{
    if(distance[s]==numeric_limits<int>::max())return;
    queue<pair<int, int>> q;
    q.push({ s,distance[s] });
    while (q.empty() == false)
    {
        int vertex = q.front().first;
        int d = q.front().second;
        q.pop();
        for (const auto& next : graph[vertex])
        {
            if (distance[next] > d + 1)
            {
                distance[next] = d + 1;
                q.push({ next,d + 1 });
            }
        }
    }
}
