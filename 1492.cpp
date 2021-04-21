#include <iostream>
#include <vector>
#define MOD 1000000007LL

using namespace std;
using ll=long long;

ll power(ll n, ll k)
{
    if(k==1LL)return n;
    if(k==0LL)return 1LL;
    ll ret=power(n,k>>1);
    ret=ret*ret;
    ret%=MOD;
    if(k&1LL)
    {
        ret*=n;
        ret%=MOD;
    }
    return ret;
}
int main()
{
    vector<vector<ll>> dp;
    vector<ll> f_dp;
    ll n,k;
    cin>>n>>k;
    dp.resize(k+2,vector<ll>(k+2));
    f_dp.resize(k+1);
    for(int i=1;i<=k+1;++i)
    {
        dp[i][0]=1;
        for(int j=1;j<i;++j){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            dp[i][j]%=MOD;
        }
        dp[i][i]=1;
    }
    f_dp[0]=n;
    f_dp[1]=(n*(n+1))/2;
    f_dp[1]%=MOD;
    for(int i=2;i<=k;++i)
    {
        ll sum=0;
        f_dp[i]=(power(1+n,i+1)-1)%MOD;
        if(f_dp[i]<0)
        {
            f_dp[i]+=MOD;
        }
        for(int p=0;p<i;++p)
        {
            sum+=(dp[i+1][p])*f_dp[p];
            sum%=MOD;
        }
        f_dp[i]-=sum;
        f_dp[i]%=MOD;
        if(f_dp[i]<0)
        {
            f_dp[i]+=MOD;
        }
        f_dp[i]*=power(i+1, MOD-2);
        f_dp[i]%=MOD;
    }
    cout<<f_dp[k];
    return 0;
}
