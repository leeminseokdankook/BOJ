#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> sum, arr, dp;
    int n, t_c, h_c;
    cin>>n;
    sum.resize(n+1);
    arr.resize(n+1);
    dp.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    cin>>t_c>>h_c;
    sort(arr.begin()+1, arr.end());
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+arr[i]*t_c;
        for(int j=i;j>=1;j--)
        {
            //j~i까진 헬기로
            int mid=(i+j)>>1;
            //mid~i까지 트럭 비용
            int right=((sum[i]-sum[mid-1])-(arr[mid])*(i-mid+1))*t_c;
            //j~mid까지 트럭 비용
            int left=((arr[mid]*(mid-j+1))-(sum[mid]-sum[j-1]))*t_c;
            dp[i]=min(dp[i], dp[j-1]+right+left+h_c);
        }
    }
    cout<<dp[n];
    return 0;
}
