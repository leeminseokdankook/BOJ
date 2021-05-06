#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll=long long;

int Find(int u, vector<int>& roots);
bool Merge(int u, int v, vector<int>& roots);
void DFS(int now, int previous, vector<vector<pair<int ,ll>>>& tree, 
    vector<vector<int>>& parents_dp, vector<vector<int>>& cost_dp, vector<int>& depthes, int depth);
ll MST(vector<pair<ll, pair<int, int>>> edges, vector<vector<pair<int ,ll>>>& tree_dest);
int Find_LCA(int u, int v,vector<vector<int>>& parents_dp, vector<int>& depthes);

int main()
{
    int n,m,h=0;
    vector<pair<ll, pair<int, int>>> edges;
    vector<vector<int>> parents_dp,max_distance_dp;
    vector<vector<pair<int, ll>>> tree;
    vector<int> depthes;
    ll mst_cost;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    tree.resize(n+1);
    depthes.resize(n+1);
    while((1<<h)<=(n+1))++h;
    parents_dp.resize(h+1, vector<int>(n+1));
    max_distance_dp.resize(h+1, vector<int>(n+1));
    for(int i=0;i<m;++i)
    {
        int u,v;
        ll cost;
        cin>>u>>v>>cost;
        edges.push_back({cost, {u,v}});
    }
    mst_cost=MST(edges,tree);
    DFS(1,1,tree,parents_dp, max_distance_dp,depthes,1);
    //make tree_dp
    for(int i=1;i<=h;++i)
    {
        for(int vertex=1;vertex<=n;++vertex)
        {
            parents_dp[i][vertex]=parents_dp[i-1][parents_dp[i-1][vertex]];
            max_distance_dp[i][vertex]=max(max_distance_dp[i-1][vertex], max_distance_dp[i-1][parents_dp[i-1][vertex]]);
        }
    }
    
    for(auto& edge:edges)
    {
        ll ans=mst_cost;
        ll add_weight=edge.first;
        int sub_weight=0;
        int u=edge.second.first, v=edge.second.second;
        int lca=Find_LCA(u,v,parents_dp,depthes);
        int diff=depthes[u]-depthes[lca];
        for(int i=0;diff;++i)
        {
            if(diff&1)
            {
                sub_weight=max(sub_weight, max_distance_dp[i][u]);
                u=parents_dp[i][u];
            }
            diff=diff>>1;
        }
        diff=depthes[v]-depthes[lca];
        for(int i=0;diff;++i)
        {
            if(diff&1)
            {
                sub_weight=max(sub_weight, max_distance_dp[i][v]);
                v=parents_dp[i][v];
            }
            diff=diff>>1;
        }
        cout<<(ans-sub_weight+add_weight)<<"\n";
    }
    return 0;
}

bool Merge(int u, int v, vector<int>& roots)
{
    int p_u=Find(u,roots);
    int p_v=Find(v,roots);
    if(p_u==p_v)return false;
    roots[p_u]=p_v;
    return true;
}

int Find(int u, vector<int>& roots)
{
    if(roots[u]==u)return u;
    return roots[u]=Find(roots[u],roots);
}

void DFS(int now, int previous, vector<vector<pair<int ,ll>>>& tree, 
    vector<vector<int>>& parents_dp, vector<vector<int>>& cost_dp, vector<int>& depthes, int depth)
    {
        depthes[now]=depth;
        for(auto& edge:tree[now])
        {
            if(edge.first==previous)continue;
            parents_dp[0][edge.first]=now;
            cost_dp[0][edge.first]=edge.second;
            DFS(edge.first,now,tree,parents_dp,cost_dp, depthes,depth+1);
        }
    }

ll MST(vector<pair<ll, pair<int, int>>> edges, vector<vector<pair<int ,ll>>>& tree_dest)
{
    ll mst_cost=0;
    vector<int> roots(tree_dest.size());
    for(int i=0;i<roots.size();++i)
    {
        roots[i]=i;
    }
    sort(begin(edges), end(edges));
    for(auto& edge: edges)
    {
        ll cost=edge.first;
        int u=edge.second.first, v=edge.second.second;
        if(Merge(u,v,roots)==true)
        {
            mst_cost+=cost;
            tree_dest[u].push_back({v,cost});
            tree_dest[v].push_back({u,cost});
        }
    }
    return mst_cost;
}

int Find_LCA(int u, int v,vector<vector<int>>& parents_dp, vector<int>& depthes)
{
    //u is always more deep
    if(depthes[u]<depthes[v])
    {
        swap(u,v);
    }
    int diff=depthes[u]-depthes[v];
    int h=parents_dp.size()-1;
    for(int i=0;diff;++i)
    {
        if(diff&1)
        {
            u=parents_dp[i][u];
        }
        diff=diff>>1;
    }
    if(u==v)return u;
    while(h>=0)
    {
        if(parents_dp[h][u]!=parents_dp[h][v])
        {
            u=parents_dp[h][u];
            v=parents_dp[h][v];
        }
        --h;
    }
    return parents_dp[0][u];
}
