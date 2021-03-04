#include <iostream>
#include <vector>
using namespace std;

int solve(int buyer, int price, int buyed, int n, 
          vector<vector<int>>& prices,vector<vector<vector<int>>>& dp);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<vector<int>>> dp;
    vector<vector<int>> prices;
    int n;
    cin>>n;
    dp.resize(n);
    prices.resize(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        dp[i].resize(10);
        for(int c=0;c<10;c++)
        {
            dp[i][c].resize(1<<n, -1);
        }
    }
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        for(int j=0;j<n;j++)
        {
            prices[i][j]=str[j]-'0';
        }
    }
    cout<<solve(0,0,1,n,prices,dp);
    return 0;
}

int solve(int buyer, int price, int buyed, int n, 
          vector<vector<int>>& prices,vector<vector<vector<int>>>& dp)
{
    int& ref=dp[buyer][price][buyed];
    if(ref!=-1)
    {
        return ref;
    }
    ref=1;
    for(int who=0;who<n;who++)
    {
        if(buyed&(1<<who))continue;
        if(prices[buyer][who]<price)continue;
        ref=max(ref, solve(who,prices[buyer][who], buyed|(1<<who),n,prices,dp )+1);
    }
    return ref;
}