#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1e9
using namespace std;

int solve(vector<vector<int>>& cost, int start ,int visited, int all_visit, int n, vector<vector<int>>& dp)
{
    int& ref=dp[start][visited];
    if(ref!=-1)
    {
        return ref;
    }
    if(visited==all_visit)
    {
        return ref=0;
    }
    ref=MAX;
    for(int i=0;i<n;++i)
    {
        if(visited&(1<<i))continue;
        ref=min(ref, solve(cost, i,visited|(1<<i), all_visit,n,dp)+cost[start][i]);
    }
    return ref;
}

int main()
{
    vector<vector<int>> cost;
    vector<vector<int>> dp;
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, all_visit=0,start;
    cin>>n>>start;
    cost.resize(n, vector<int>(n));
    dp.resize(n, vector<int>(1<<n, -1));
    for(int i=0;i<n;++i)
    {
        all_visit|=1<<i;
        for(int j=0;j<n;++j)
        {
            cin>>cost[i][j];
        }
    }
    for(int k=0;k<n;++k)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                cost[i][j]=min(cost[i][j], cost[i][k]+cost[k][j]);
            }
        }
    }
    cout<<solve(cost,start,1<<start,all_visit,n,dp);
    return 0;
}
