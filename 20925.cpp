#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<vector<int>> dp, move_cost;
    vector<pair<int, int>> table;
    int n,t,ans=-1;
    cin>>n>>t;
    dp.resize(n+1,vector<int>(t+1, -1));
    table.resize(n+1);
    move_cost.resize(n+1, vector<int>(n+1));
    for(int i=1;i<=n;i++)
    {
        cin>>table[i].first>>table[i].second;
    }
    for(int i=1;i<=n;++i)
    {
        dp[i][0]=0;
        for(int j=1;j<=n;++j)
        {
            cin>>move_cost[i][j];
        }
    }
    for(int time=1;time<=t;++time)
    {
        for(int i=1;i<=n;i++)
        {
            if(dp[i][time-1]>=table[i].first)
            {
                dp[i][time]=dp[i][time-1]+table[i].second;
            }
            //i -> 현재 사냥터 
            for(int j=1;j<=n;++j)
            {
                //j-> 이전 사냥터
                if(time<=move_cost[i][j])continue;
                if(dp[j][time-move_cost[i][j]]==-1)continue;
                if(dp[j][time-move_cost[i][j]]<table[i].first)continue;
                else dp[i][time]=max(dp[i][time], dp[j][time-move_cost[i][j]]);
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        ans=max(ans, dp[i][t]);
    }
    cout<<ans;
    return 0;
}
