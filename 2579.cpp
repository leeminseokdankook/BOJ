#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> dp, values;
    int n;
    cin>>n;
    dp.resize(n+1);
    values.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>values[i];
    }
    if(n==1)
    {
        cout<<values[1];
    }
    else if(n==2)
    {
        cout<<values[1]+values[2];
    }
    else
    {
        dp[0]=0;
        dp[1]=values[1];
        dp[2]=dp[1]+values[2];
        for(int i=3;i<=n;++i)
        {
            dp[i]=max(dp[i-2]+values[i], dp[i-3]+values[i-1]+values[i]);
        }
        cout<<dp[n];
        
    }
    return 0;
}
