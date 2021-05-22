#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> rectangle;
    vector<vector<int>> dp;
    vector<int> max_heights;
    //max_heights[i] i번째 행까지 가장 긴 연속된 세로 1의 길이
    int n,m;
    int ans=0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    rectangle.resize(n);
    max_heights.resize(n);
    dp.resize(n,vector<int>(m));
    for(auto& row:rectangle)
    {
        cin>>row;
    }
    for(int i=0;i<m;++i)
    {
        if(rectangle[0][i]=='1')
        {
            dp[0][i]=1;
            max_heights[0]=1;
        }
    }
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(rectangle[i][j]=='1')
            {
                dp[i][j]=dp[i-1][j]+1;
                max_heights[i]=max(max_heights[i],dp[i][j]);
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        vector<int> arr(max_heights[i]+1);
        for(int j=0;j<m;++j)
        {
            ++arr[dp[i][j]];
        }
        int w=0;
        for(int h=max_heights[i];h>=1;--h)
        {
            if(arr[h]==0)continue;
            w+=arr[h];
            ans=max(ans, w*h);
        }
    }
    cout<<ans;
    return 0;
}
