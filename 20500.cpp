#include <iostream>
#include <vector>
#define MOD 1000000007LL
using namespace std;

int main()
{
    vector<long long> dp;
    int n;
    cin>>n;
    if(n==0||n==1)
    {
        cout<<0<<"\n";
    }
    else if(n==2||n==3)
    {
        cout<<1<<"\n";
    }
    else{
        dp.resize(n+1);
        dp[0]=dp[1]=0;
        dp[2]=dp[3]=1;
        for(int i=4;i<=n;i++)
        {
            dp[i]=((dp[i-2]*3)%MOD+(dp[i-3]*2)%MOD)%MOD;
        }
        cout<<dp[n]<<"\n";
    }
    return 0;
    
}
