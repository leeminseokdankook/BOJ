#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> dp, a;
    int n, w;
    cin>>w>>n;
    a.resize(n);
    dp.resize(w+1);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j]>w)continue;
            if(dp[w-a[i]-a[j]]==1)
            {
                cout<<"YES";
                return 0;
            }
        }
        for(int j=0;j<i;j++)
        {
            if(a[i]+a[j]>w)continue;
            dp[a[i]+a[j]]=1;
        }
    }
    cout<<"NO";
    return 0;
}
