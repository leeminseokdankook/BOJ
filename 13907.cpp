#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

/*

백준 13907

*/

unsigned int Solve(list<pair<unsigned int, unsigned int>>& path, int inc)
{
    unsigned int ret=(INT32_MAX<<1)|1;
    for(auto iter=path.begin();iter!=path.end();)
    {
        iter->second+=iter->first*inc;
        if(ret>iter->second)
        {
            ret=iter->second;
            iter++;
        }
        else
        {
            iter=path.erase(iter);
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<list<pair<int, int>>> w_graph;
    vector<int> dist;
    list<pair<unsigned int, unsigned int>> path;
    /*
    *   dist[j] -> s에서  j로 가는 최소 비용
    */
    queue<pair<int, int>> pq;
    //pq.top().first -> 비용
    //second -> 현재 지점
    int n, m, k, s, e;
    unsigned int depth=0;
    cin >> n >> m >> k;
    w_graph.resize(n + 1);
    dist.resize(n + 1, INT32_MAX);
    cin >> s >> e;
    while (m--)
    {
        int a, b;
        unsigned int w;
        cin >> a >> b >> w;
        w_graph[a].push_back({ b,w });
        w_graph[b].push_back({ a,w });
    }
    dist[s] = 0;
    pq.push({0,s});
    while (pq.empty() == false)
    {
        int temp=pq.size();
        depth++;
        while(temp--)
        {
            int from=pq.front().second;
            int weight=pq.front().first;
            pq.pop();
            for(auto& next:w_graph[from])
            {
                int to=next.first;
                unsigned int next_cost=weight+next.second;
                if(dist[to]>next_cost)
                {
                    dist[to]=next_cost;
                    if(to==e)
                    {
                        path.push_back({depth, next_cost});
                    }
                    pq.push({next_cost, to});
                }
            }
        }
    }
    cout<<Solve(path, 0)<<'\n';
    while(k--)
    {
        int p;
        cin>>p;
        cout<<Solve(path, p)<<'\n';
    }
    return 0;
}
