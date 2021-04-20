#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<list<int>>& tree, int pre, int parent, int cost, 
          int max_color,vector<vector<int>>& dp);

int main()
{
    vector<list<int>> tree;
    vector<vector<int>> dp;
    int max_color=1;
    int n,ans=INT32_MAX;
    cin>>n;
    tree.resize(n+1);
    while((1<<max_color)<=n)
    {
        max_color++;
    }
    dp.resize(n+1,vector<int>(max_color+1, -1));
    for(int i=1;i<n;i++)
    {
        int v,u;
        cin>>v>>u;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i=1;i<=max_color;i++)
    {
        ans=min(ans, solve(tree,1,1,i,max_color,dp));
    }
    cout<<ans;
}

int solve(vector<list<int>>& tree, int pre, int parent, int cost, 
          int max_color,vector<vector<int>>& dp)
{
    int& ref=dp[pre][cost];
    int child_cost=0;
    if(ref!=-1)
    {
        return ref;
    }
    ref=cost;
    for(auto iter=tree[pre].begin();iter!=tree[pre].end();iter++)
    {
        if(*iter==parent)continue;
        int tmp=INT32_MAX;
        for(int i=1;i<=max_color;i++)
        {
            if(i==cost)continue;
            tmp=min(tmp, solve(tree,*iter,pre,i,max_color,dp));
        }
        child_cost+=tmp;
    }
    ref+=child_cost;
    return ref;
}
