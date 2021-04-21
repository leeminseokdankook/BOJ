#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int dp[3][1000], n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>dp[0][0]>>dp[1][0]>>dp[2][0];
    for(int i=1;i<n;++i)
    {
        int r,g,b;
        cin>>r>>g>>b;
        dp[0][i]=min(dp[1][i-1], dp[2][i-1])+r;
         dp[1][i]=min(dp[0][i-1], dp[2][i-1])+g;
         dp[2][i]=min(dp[0][i-1], dp[1][i-1])+b;
    }
    cout<<min({dp[0][n-1], dp[1][n-1], dp[2][n-1]});
    return 0;
}
