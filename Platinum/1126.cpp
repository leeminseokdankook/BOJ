#include <iostream>
#include <vector>
using namespace std;

const int MAX_HEIGHT_DIFF=500000>>1;

int solve(int n, vector<int>& arr, vector<vector<int>>& dp, int index, int height_diff);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<vector<int>> dp;
    vector<int> arr;
    cin>>n;
    arr.resize(n);
    dp.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        dp[i].resize(MAX_HEIGHT_DIFF+1, -1);
    }
    solve(n,arr,dp,0,0);
    if(dp[0][0]>0)
    {
        cout<<dp[0][0];
    }
    else
    {
        cout<<-1;
    }
    return 0;
}

int solve(int n, vector<int>& arr, vector<vector<int>>& dp, int index, int height_diff)
{
    if(index==n)
    {
        if(height_diff==0)
        {
            return 0;
        }
        else
        {
            return INT32_MIN;
        }
    }
    if(height_diff>MAX_HEIGHT_DIFF)
    {
        return INT32_MIN;
    }
    
    int& ref=dp[index][height_diff];
    if(ref!=-1)
    {
        return ref;
    }
    ref=INT32_MIN;
    ref=max(ref,solve(n,arr,dp,index+1, height_diff)); //현재 상태를 그대로 둠
    //더 높은 곳에 쌓음
    ref=max(ref,solve(n,arr,dp,index+1,height_diff+arr[index]));
    //낮은 곳에 쌓음
    if(arr[index]>height_diff)
    {
        ref=max(ref, height_diff+solve(n,arr,dp,index+1, arr[index]-height_diff));
    }
    else
    {
        ref=max(ref, arr[index]+solve(n,arr,dp,index+1, height_diff-arr[index]));
    }
    return ref;
}
