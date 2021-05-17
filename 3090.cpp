#include <iostream>
#include <vector>
using namespace std;

using ll=long long;
bool is_posible(vector<ll> arr, ll diff, ll t)
{
    ll cnt=0;
    for(int i=0;i<arr.size()-1;++i)
    {
        if(arr[i+1]-arr[i]>diff)
        {
            ll k=arr[i+1]-(arr[i]+diff);
            cnt+=k;
            arr[i+1]=arr[i]+diff;
        }
    }
    for(int i=arr.size()-1;i>=1;--i)
    {
        if(arr[i-1]-arr[i]>diff)
        {
            ll k=arr[i-1]-(arr[i]+diff);
            cnt+=k;
            arr[i-1]=arr[i]+diff;
        }
    }
    return cnt<=t;
}

int main()
{
    vector<ll> arr;
    int n;
    ll t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>t;
    arr.resize(n);
    for(ll& val:arr)
    {
        cin>>val;
    }
    ll l=0,r=1e9;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(is_posible(arr,mid,t)==true)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    for(int i=0;i<arr.size()-1;++i)
    {
        if(arr[i+1]-arr[i]>l)
        {
            arr[i+1]=arr[i]+l;
        }
    }
    for(int i=arr.size()-1;i>=1;--i)
    {
        if(arr[i-1]-arr[i]>l)
        {
            arr[i-1]=arr[i]+l;
        }
    }
    for(ll& e:arr)
    {
        cout<<e<<" ";
    }
    return 0;
}
