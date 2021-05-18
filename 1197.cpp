#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find(int x, vector<int>& roots);
bool merge(int x ,int y,vector<int>& roots);

int main()
{
    vector<int> roots;
    vector<pair<int ,pair<int, int>>> edges;
    int v,e, edge_cnt=0,ans=0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>v>>e;
    edges.resize(e);
    roots.resize(v+1);
    for(int i=1;i<=v;++i){
        roots[i]=i;
    }
    for(int i=0;i<e;++i){
        int v,u,w;
        cin>>v>>u>>w;
        edges[i]={w,{v,u}};
    }
    sort(begin(edges), end(edges));
    v--;
    for(auto iter=begin(edges);edge_cnt<v;++iter)
    {
        int v=iter->second.first,u=iter->second.second;
        int w=iter->first;
        if(merge(v,u,roots)==true)
        {
            ans+=w;
            ++edge_cnt;
        }
    }
    cout<<ans;
    return 0;
}

int find(int x, vector<int>& roots){
    if(x==roots[x])return x;
    roots[x]=find(roots[x],roots);
    return roots[x];
}

bool merge(int x, int y, vector<int>& roots){
    int p_x=find(x,roots), p_y=find(y,roots);
    if(p_x==p_y)return false;
    roots[p_x]=p_y;
    return true;
}
