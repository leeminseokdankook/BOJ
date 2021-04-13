#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

bool IsAble(vector<vector<pair<int, int>>>& graph, int free_cost, int n, int k)
{
    //free cost 이상은 무료
    vector<int> dist(n+1, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push({0,1});
    dist[1]=0;
    while(pq.empty()==false)
    {
        auto pick=pq.top();
        pq.pop();
        if(dist[pick.second]<pick.first)continue;
        for(auto& iter:graph[pick.second])
        {
            int next=iter.first;
            int next_cost=pick.first+(iter.second>free_cost?1:0);
            if(dist[next]>next_cost)
            {
                dist[next]=next_cost;
                pq.push({next_cost, next});
            }
        }
    }
    return dist[n]<=k;
}
int main()
{
    vector<vector<pair<int, int>>> graph;
    int n,p,k, ans=-1, l,r;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>p>>k;
    graph.resize(n+1);
    while(p--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    l=0;r=1e7;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(IsAble(graph,mid,n,k)==true)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
