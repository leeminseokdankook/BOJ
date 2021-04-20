#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int s, int e, vector<vector<int>>& dp, vector<int>& colors)
{
    int& ref=dp[s][e];
    if(ref!=-1)
    {
        return ref;
    }
    if(s==e)
    {
        return ref=0;
    }
    ref=INT32_MAX;
    for(int i=s;i<e;++i)
    {
        int weight=colors[s]!=colors[i+1];  //s번째 전구와 색을 맞춤
        ref=min(ref, solve(s,i,dp,colors)+solve(i+1,e,dp,colors)+weight);
    }
    return ref;
}
int main()
{
    int n,c;
    vector<vector<int>> dp;
    vector<int> colors;
    cin>>n>>c;
    dp.resize(n+1, vector<int>(n+1, -1));
    colors.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>colors[i];
    }
    cout<<solve(1,n,dp,colors);
    return 0;
}
