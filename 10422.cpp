#include <iostream>
#include <vector>
#define MOD 1000000007LL;
using namespace std;
using ll=long long;

int main()
{
    vector<ll> ans(2501);
    int t,n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ans[0]=ans[1]=1LL;
    for(int i=2;i<=2500;++i)
    {
        for(int j=1;j<=i;++j)
        {
            ans[i]+=(ans[j-1]*ans[i-j])%MOD;
        }
        ans[i]%=MOD;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n&1)
        {
            cout<<"0\n";
        }
        else
        {
            cout<<ans[n>>1]<<"\n";
        }
    }
    return 0;
}
