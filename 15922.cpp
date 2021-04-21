#include <vector>
#include <iostream>
using namespace std;
using ll=long long;

int main()
{
    int n;
    ll s, e,ans=0LL;
    vector<pair<ll, ll>> v;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    s=v[0].first;e=v[0].second;
    for(int i=1;i<n;i++)
    {
        //다음이 현재 구간에 포함
        if(v[i].first>=s&&e>=v[i].second)continue;
        
        //걸쳐있음
        else if(v[i].first<=e&&v[i].second>e)e=v[i].second;
        
        //벗어남
        else
        {
            ans+=e-s;
            s=v[i].first;
            e=v[i].second;
        }
    }
    ans+=e-s;
    cout<<ans;
    return 0;
}
