#include <iostream>
#include <vector>
using namespace std;
using ll=long long;

ll combi(int n, int k, ll m, vector<vector<ll>>& dp)
{
    ll& ref=dp[n][k];
    if(ref!=-1LL)
    {
        return ref;
    }
    if(n<k)
    {
        return ref=0;
    }
    if(n==k||n==0||k==0)
    {
        return ref=1;
    }
    return ref=(combi(n-1,k-1,m,dp)+combi(n-1,k,m,dp))%m;
}
int main()
{
    vector<vector<ll>> dp;
    ll n,k,m, ans=1LL;
    cin>>n>>k>>m;
    dp.resize(m, vector<ll>(m,-1LL));
    while(n!=0||k!=0)
    {
        ans*=combi(n%m,k%m,m,dp);
        ans%=m;
        n/=m;
        k/=m;
    }
    cout<<ans;
    return 0;
}
