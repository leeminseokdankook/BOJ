#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int solve(vector<vector<int>>& dp, vector<int>& arr, int front, int back, int diff)
{
    //dp[front][back]=dp[back][next]+1
    int& ref=dp[front][back];
    if(ref!=-1)
    {
        return ref;
    }
    ref=2;
    int next=lower_bound(begin(arr)+back+1, end(arr), arr[back]+diff)-begin(arr);
    if(next<arr.size()&&arr[next]==arr[back]+diff)
    {
        ref=solve(dp,arr,back,next, diff)+1;
    }
    return ref;
}

int main()
{
    int n,ans=1;
    vector<vector<int>> dp;
    vector<int> arr;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    arr.resize(n);
    dp.resize(n, vector<int>(n,-1));
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    sort(begin(arr), end(arr));
    for(int i=0;i<n-1;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(dp[i][j]!=-1)continue;
            ans=max(solve(dp,arr,i,j,arr[j]-arr[i]), ans);
        }
    }
    cout<<ans;
    return 0;
}
