#include <iostream>
#include <vector>
#define MOD 1000000007LL
using namespace std;

int main()
{
    int n;
    long long ans;
    cin>>n;
    if(n==1)
    {
    	ans=0LL;
    }
    else if(n==2)
    {
        ans=1LL;
    }
    else if(n==3)
    {
    	ans=4LL;
    }
    else if(n==4)
    {
    	ans=10LL;
    }
    else
    {
    	vector<long long> dp1, dp2;
    	dp1.resize(n+1);
    	dp2.resize(n+1);
    	dp1[0]=dp2[0]=dp1[1]=dp2[1]=1;
    	dp1[2]=1;dp2[2]=2;
    	dp1[3]=4;dp1[4]=10;
    	for(int i=3;i<=n;i++)
    	{
        	dp2[i]=(dp2[i-1]+dp2[i-2]+dp2[i-3])%MOD;
		}
		for(int i=5;i<=n;i++)
		{
			dp1[i]=(dp1[i-1]+dp1[i-2]*2+dp1[i-3]*3+dp2[i-2]+dp2[i-3]*2)%MOD;
		}
		ans=dp1[n];
    }
    cout<<ans;
    return 0;
}
