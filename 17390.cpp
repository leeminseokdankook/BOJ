#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<unsigned int> arr, sum;
    int n,q;
    cin>>n>>q;
    arr.resize(n+1);
    sum.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+arr[i];
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<"\n";
    }
    return 0;
}
