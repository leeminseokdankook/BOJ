#include <iostream>
#include <vector>
using ll=long long;
using namespace std;

void InitMobius(vector<int>& mobius)
{
    mobius[1]=1;
    for(int j=1;j<=1000000;++j)
    {
        for(int k=2*j;k<=1000000;k=k+j)
        {
            mobius[k]-=mobius[j];
        }
    }
}
int main()
{
    vector<int> mobius(1000001);
    ll left=0,k,right;
    cin>>k;
    right=2*k;
    InitMobius(mobius);
    while(left+1<right)
    {
        ll mid=(left+right)>>1;
        ll ans=0LL;
        for(ll i=1;i*i<=mid;++i)
        {
            ans+=(mobius[i]*(mid/(i*i)));
        }
        if(ans<k)
        {
            left=mid;
        }
        else
        {
            right=mid;
        }
    }
    cout<<right;
    return 0;
}
