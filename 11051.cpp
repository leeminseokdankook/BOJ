#include <iostream>
#include <vector>
using namespace std;

const int MOD=10007;
int power(int n, int k)
{
    if(k==0)return 1;
    if(k==1)return n;
    int ret=power(n,k>>1)%MOD;
    ret=ret*ret%MOD;
    if(k&1)
    {
        ret*=n;
        ret%=MOD;
    }
    return ret;
}
int main()
{
    int n,k,ans;
    vector<int> factorial;
    cin>>n>>k;
    factorial.resize(n+1,1);
    for(int i=1;i<=n;++i)
    {
        factorial[i]=i*factorial[i-1]%MOD;
    }
    ans=(factorial[n]*power(factorial[k],MOD-2))%MOD;
    ans*=power(factorial[n-k], MOD-2);
    ans%=MOD;
    cout<<ans;
    return 0;
}
