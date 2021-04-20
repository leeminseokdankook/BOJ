#include <iostream>
using namespace std;
using ll=long long;
ll g(long long n, long long k)
{
    if(n==1LL)
    {
        return 0LL;
    }
    if(k==1LL)
    {
        return (n-1LL);
    }
    else if(n<k)
    {
        return (g(n-1LL,k)+k)%n;
    }
    else
    {
        ll n_=n-(n/k);
        ll ret=g(n_,k);
        ret-=(n%k);
        if(ret<0LL)ret+=(n_);
        return (k*(ret%n_))/(k-1LL);
    }
}

int main()
{
    ll n,k;
    cin>>n>>k;
    cout<<g(n,k)+1LL;
    return 0;
}
