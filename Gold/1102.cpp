#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Solve(int n,int p, int pre, int state, int excuting_cnt, vector<vector<int>>& cost,
          vector<vector<int>>& dp);
int main()
{
    int n,p, state=0, exe_cnt=0;
    string str;
    vector<vector<int>>  dp, cost;
    cin>>n;
    cost.resize(n,vector<int>(n));
    dp.resize(n, vector<int>(1<<n, -1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>cost[i][j];
        }
    }
    cin>>str;
    cin>>p;
    if(p==0)
    {
        cout<<0;
    }
    else{
    for(int i=0;i<n;i++)
    {
        if(str[i]=='Y')
        {
            exe_cnt++;
            state|=1<<i;
        }
    }
    int ans=INT32_MAX;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='Y')
        {
            ans=min(ans,Solve(n, p, i, state, exe_cnt,cost, dp));
        }
    }
    if(ans==INT32_MAX)
    {
        cout<<-1;
    }
    else
    {
        cout<<ans;
    }
    }    
    return 0;
}

int Solve(int n,int p, int pre, int state, int excuting_cnt, vector<vector<int>>& cost,
          vector<vector<int>>& dp)
{
    if(excuting_cnt>=p)
    {
        return 0;
    }
    int& ref=dp[pre][state];
    if(ref!=-1) return ref;
    ref=INT32_MAX;
    for(int i=0;i<n;i++)
    {
        if((state&(1<<i))==0)
        {
            int next_state=state|(1<<i);
            for(int j=0;j<n;j++)
            {
                if(next_state&(1<<j))
                {
                    int sub=Solve(n,p,j,next_state,excuting_cnt+1, cost, dp);
                    if(sub==INT32_MAX)continue;
                    ref=min(ref, cost[pre][i]+sub);
                }
            }
        }
    }
    return ref;
}