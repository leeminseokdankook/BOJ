#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void DFS(int now ,int previous, vector<vector<pair<int, int>>>& tree, vector<bool>& visited, 
            int dist, vector<int>& distances, int& max_distance_vertex);

template<class T>
void Vector_Reset(vector<T>& vec, int size, T&& val);
int main()
{
    int n;
    int u,v;
    vector<int> distances_u, distances_v;
    vector<bool> visited;
    vector<vector<pair<int, int>>> tree;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    u=v=1;
    cin>>n;
    Vector_Reset(tree,n+1, vector<pair<int, int>>());
    Vector_Reset(distances_v, n+1, 0);
    Vector_Reset(distances_u, n+1, 0);
    for(int i=1;i<n;++i)
    {
        int a,b,w;
        cin>>a>>b>>w;
        tree[a].push_back({b,w});
        tree[b].push_back({a,w});
    }
    DFS(1,1,tree,visited,0,distances_v,v);
    Vector_Reset(distances_v, n+1, 0);
    DFS(v,v,tree,visited,0,distances_v,u);
    DFS(u,u,tree,visited,0,distances_u,u);
    for(int i=1;i<=n;++i)
    {
        cout<<max(distances_u[i], distances_v[i])<<"\n";
    }
    return 0;
}

template<class T>
void Vector_Reset(vector<T>& vec, int size, T&& val)
{
    vec.clear();
    vec.resize(size, val);
}

void DFS(int now ,int previous, vector<vector<pair<int, int>>>& tree, vector<bool>& visited, 
            int dist, vector<int>& distances, int& max_distance_vertex)
{
    distances[now]=max(dist,distances[now]);
    if(distances[now]>distances[max_distance_vertex])
    {
        max_distance_vertex=now;
    }
    for(auto& edge:tree[now])
    {
        if(edge.first==previous)continue;
        DFS(edge.first, now,tree,visited,dist+edge.second,distances, max_distance_vertex);
    }
}
