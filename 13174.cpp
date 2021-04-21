#include <iostream>
#include <vector>
#define MOD 1000000007LL

using namespace std;
using ll=long long;

ll power(ll k, ll n)
{
    if(n==0) return 1;
    if(n==1) return k;
    ll half=power(k, n/2);
    ll ret=(half*half)%MOD;
    if(ret<0LL)
    {
        ret+=MOD;
    }
    if(n&1LL)
    {
        ret=ret*k%MOD;
    }
    return ret;
}

ll power(ll k, ll n, vector<ll>& dp)
{
    ll& ref=dp[n];
    if(ref!=-1)
    {
        return ref;
    }
    if(n==0LL) return ref=1LL;
    if(n==1LL) return ref=k;
    ll half=power(k, n/2);
    ref=(half*half)%MOD;
    if(ref<0LL)
    {
        ref+=MOD;
    }
    if(n&1LL)
    {
        ref=ref*k%MOD;
    }
    return ref;
}

int main()
{
    vector<ll> catal, dp;
    ll n,k, ans;
    cin>>n>>k;
    catal.resize(n/2+1);
    dp.resize(n/2+1, -1);
    catal[0]=1;
    for(int i=0;i<static_cast<int>(n/2);++i)
    {
        catal[i+1]=(((2*(2*i+1)*catal[i])%MOD)*(power(i+2, MOD-2)%MOD))%MOD;
    }
    ans=1;  //S0
    for(int i=0;i<static_cast<int>(n);++i)
    {
        if(i%2==1)
        {
            ans=(k+1)*ans%MOD;
        }
        else
        {
            ans=((k+1)*ans%MOD-(catal[i/2]*power(k,i/2, dp)%MOD))%MOD;
            if(ans<0)
            {
                ans+=MOD;
            }
        }
    }
    cout<<ans;
    return 0;
}
