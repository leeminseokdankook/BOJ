#include <iostream>
#include <vector>
#include <list>
using namespace std;

void DFS(vector<list<pair<int, int>>> &graph, int prv, int now, vector<int>& tree, 
         vector<vector<int>>& cost_dp, vector<vector<int>>& parent_dp);

int main()
{
    vector<list<pair<int, int>>> graph;
    vector<int> tree;    //tree[i] ={i's parent,  cost of i to i's parent}
    vector<int> Energy;
    vector<vector<int>> parent_dp, cost_dp;
    //dp[i][j] == j 의 pow(2,i) 번째 부모
    int n,h=0;
    cin>>n;
    while((1<<h)<=n)h++;
    parent_dp.resize(h+1, vector<int>(n+1));
    cost_dp.resize(h+1, vector<int>(n+1));
    graph.resize(n+1);
    tree.resize(n+1);
    Energy.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>Energy[i];
    }
    for(int i=1;i<n;i++)
    {
        int v,u,w;
        cin>>v>>u>>w;
        graph[v].push_back({u,w});
        graph[u].push_back({v,w});
    }
    tree[1]=1;
    DFS(graph, 1,1,tree,cost_dp, parent_dp);
    cost_dp[0][1]=0;parent_dp[0][1]=1;
    for(int level=1;level<=h;level++)
    {
        for(int v=1;v<=n;v++)
        {
            parent_dp[level][v]=parent_dp[level-1][parent_dp[level-1][v]];
            cost_dp[level][v]=cost_dp[level-1][parent_dp[level-1][v]]+cost_dp[level-1][v];
        }
    }
    for(int i=1;i<=n;i++)
    {
        //각 정점마다
        int v=i;
        int E=Energy[i];
        for(int level=h;level>=0;level--)
        {
            //2^level 까지 갈 수 있나 확인
            if(cost_dp[level][v]<=E)
            {
                E-=cost_dp[level][v];
                v=parent_dp[level][v];
            }
        }
        cout<<v<<'\n';
    }
}

void DFS(vector<list<pair<int, int>>> &graph, int prv, int now, vector<int>& tree, 
         vector<vector<int>>& cost_dp, vector<vector<int>>& parent_dp)
{
    for(auto& v:graph[now])
    {
        if(v.first==prv)continue;
        cost_dp[0][v.first]=v.second;
        tree[v.first]=parent_dp[0][v.first]=now;
        DFS(graph, now, v.first, tree, cost_dp, parent_dp);
    }
}
