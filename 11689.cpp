#include <iostream>
using namespace std;
using ll=long long;

int main()
{
    double ans=0.0;
    ll n;
    cin>>n;
    ans=n;
    for(ll i=2;i*i<=n;++i)
    {
        if(n%i!=0)continue;
        while(n%i==0)n=n/i;
        ans*=(1.0-(1.0/i));
    }
    if(n>1)
    {
        ans*=(1.0-(1.0/n));
    }
    cout<<static_cast<ll>(ans);
    return 0;
}
