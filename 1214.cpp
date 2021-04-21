#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

using ll=long long;

int main()
{
    ll P,Q,D;
    ll ans=numeric_limits<ll>::max();
    cin>>D>>P>>Q;
    if(D%P==0||D%Q==0)
    {
        ans=D;
    }
    else
    {
        ll minimum=min(P,Q);
        ll maximum=max(P,Q);
        int max_p=(D/maximum)+1;
        for(int p=0;p<=max_p;++p)
        {
            ll val=maximum*p;
            ll q_cnt=0;
            ll result;
            if(val<D)
            {
                q_cnt=(D-val)/minimum+((D-val)%minimum==0?0:1);
            }
            result=val+q_cnt*minimum;
            if(result==ans)break;
            ans=min(ans, val+q_cnt*minimum);
        }
    }
    cout<<ans;
    return 0;
}
