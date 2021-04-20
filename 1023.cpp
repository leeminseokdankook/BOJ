#include <iostream>
#include <vector>
using namespace std;
using ll=long long;

int main() {
	// your code goes here
	int n;
	ll k;
	cin>>n>>k;
	if(n&1==1)
	{
		//n이 홀수이면
		//괄호 문자열이 존재할 수 없음
		for(int i=(n-1);i>=0;i--)
		{
			if((1LL<<i)&k)
			{
				cout<<")";
			}
			else
			{
				cout<<"(";
			}
		}
	}
	else
	{
		vector<vector<ll>> dp;
        //dp[i][j] ->  '(' 가 i개, ')'가 j개 이면서 괄호문자열의 개수
        //i=0이면 dp[i][j]=1;
		dp.resize(n+1,vector<ll>(n+1,0LL));
		for(int i=0;i<=n;i++)
		{
			dp[0][i]=1;
			for(int j=1;j<=i;j++)
			{
				dp[j][i]=dp[j-1][i]+dp[j][i-1];
			}
		}
		if(k>=((1LL<<n)-dp[n>>1][n>>1]))
		{
			cout<<"-1";
		}
		else
		{
			int a=n>>1;    //a는 '(' 의 개수
			int b=a;       //b는 ')' 의 개수
			bool flag=false;    //flag 가  true 면 괄호문자열을 확인할 필요가 없음
			for(int i=(n-1);i>=0;i--)
			{
				if(flag)
				{
					if(k<(1LL<<i))
					{
						cout<<"(";
					}
					else
					{
						cout<<")";
						k=k-(1LL<<i);
					}
				}
				else
				{
					if(k<((1LL<<i)-dp[a-1][b]))
					{
						cout<<"(";
						a--;
						if(a==0LL)
						{
							flag=true;
						}
					}
					else
					{
						k=k-((1LL<<i)-dp[a-1][b]);
						cout<<")";
						b--;
						if(a>b)
						{
							flag=true;
						}
					}
				}
			}
		}
	}
	return 0;
}