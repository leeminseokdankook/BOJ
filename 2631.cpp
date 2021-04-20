#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> dp;
    vector<int> order;
    int n,ans=0;
    cin>>n;
    dp.resize(n+1);
    order.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>order[i];
    }
    dp[1]=1;
    for(int i=2;i<=n;++i)
    {
        dp[i]=1;
        for(int j=1;j<i;++j)
        {
            if(order[i]>order[j])
            {
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(dp[i],ans);
    }
    cout<<n-ans;
    return 0;
}
