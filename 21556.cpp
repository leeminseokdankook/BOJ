#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

int main()
{
    vector<ll> arr;
    int n;
    ll l,r;
    ll target,ans;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    target=(static_cast<ll>(n)*(n-1))/2;
    target+=1;
    target=target>>1;
    arr.resize(n);
    for(ll& ele:arr)
    {
        cin>>ele;
    }
    sort(begin(arr), end(arr));
    l=arr[0]+arr[1],r=arr[n-1]+arr[n-2];
    ans=r;
    while(l<r)
    {
        ll mid=(l+r)>>1;
        ll sum=0;
        int left_index=0;
        int right_index=n-1;
        while(left_index<right_index)
        {
            if(arr[right_index]+arr[left_index]<=mid)
            {
                ++left_index;
            }
            else
            {
                sum+=(right_index-left_index);
                --right_index;
            }
        }
        if(sum>target)
        {
            //mid 값보다 큰 조합이 S/2 보다 크다면
            //값이 감소
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    cout<<r;
    return 0;
}
