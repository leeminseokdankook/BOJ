#include <iostream>
using namespace std;

int main()
{
    int arr[1001]={0};
    int psum[1001]={0};
    int n, ans=0, order=1, min_p=1001, max_p=-1;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int val;
        cin>>val;
        ++arr[val];
        max_p=max_p>val?max_p:val;
        min_p=min_p>val?val:min_p;
    }
    psum[0]=0;
    for(int i=min_p;i<=max_p;++i)
    {
        while(arr[i])
        {
            psum[order]=psum[order-1]+i;
            ans+=psum[order];
            --arr[i];
            ++order;
        }
    }
    cout<<ans;
    return 0;
}
