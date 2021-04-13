#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 16e8
using namespace std;

int TSP(int pre, int visited,int n ,int all_visited, vector<vector<int>>& w, vector<vector<int>>& dp);

int main()
{
    int n, all_visited=0;
    vector<vector<int>> dp, w;
    cin>>n;
    w.resize(n,vector<int>(n));
    dp.resize(n, vector<int>(1<<n, INT32_MAX));
    for(int i=0;i<n;i++){
        for(int& x:w[i])
        {
            cin>>x;
        }
    }
    all_visited=(1<<n)-1;
    cout<<TSP(0,1, n, all_visited,w,dp);
    return 0;
}

int TSP(int pre, int visited,int n ,int all_visited, vector<vector<int>>& w, vector<vector<int>>& dp)
{
    if(visited==all_visited)
    {
        if(w[pre][0]==0)return 0;
        return w[pre][0];
    }
    int& ref=dp[pre][visited];
    if(ref!=INT32_MAX)
    {
        return ref;
    }
    for(int p=0;p<n;p++)
    {
        if(visited&(1<<p))continue;
        if(w[pre][p]==0)continue;
        int sub=TSP(p,visited|(1<<p), n, all_visited,w,dp);
        if(sub==0)continue;
        ref=min(ref, sub+w[pre][p]);
    }
    if(ref==INT32_MAX) return 0;
    return ref;
}
