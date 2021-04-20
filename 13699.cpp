#include <iostream>
#include <vector>
using ll=long long;
using namespace std;

ll solution(int n, vector<ll>& dp)
{
    ll& ref=dp[n];
    if(ref!=-1LL) return ref;
    if(n==0) return ref=1LL;
    ref=0;
    for(int i=0;i<n;++i)
    {
        ref+=(solution(n-i-1,dp)*solution(i,dp));
    }
    return ref;
}

int main()
{
    vector<ll> dp;
    int n;
    cin>>n;
    dp.resize(n+1,-1LL);
    cout<<solution(n,dp);
    return 0;
}
