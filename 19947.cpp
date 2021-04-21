#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> dp;
    int y, h;
    cin>>h>>y;
    dp.resize(y+1);
    dp[0]=h;
    for(int i=1;i<=y;++i)
    {
        dp[i]=dp[i-1]*1.05;
        if(i>=3)
        {
            dp[i]=max(dp[i], static_cast<int>(dp[i-3]*1.2));
        }
        if(i>=5)
        {
            dp[i]=max(dp[i], static_cast<int>(dp[i-5]*1.35));
        }
    }
    cout<<dp[y];
    return 0;
}
