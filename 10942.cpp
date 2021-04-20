#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& arr, int l, int r, vector<vector<int>>& dp);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr;
    vector<vector<int>> dp;
    int n,m;
    cin>>n;
    arr.resize(n+1);
    dp.resize(n+1, vector<int>(n+1, -1));
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int l=1;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            solve(arr,l,r,dp);
        }
    }
    cin>>m;
    while(m--)
    {
        int l, r;
        cin>>l>>r;
        cout<<dp[l][r]<<"\n";
    }
}

int solve(vector<int>& arr, int l, int r, vector<vector<int>>& dp)
{
    int &ref=dp[l][r];
    if(ref!=-1)
    {
        return ref;
    }
    ref=1;
    if(l==r)
    {
        return ref=1;
    }
    if(arr[l]!=arr[r])
    {
        return ref=0;
    }
    if(l+1<r)
    {
        if(solve(arr,l+1,r-1,dp)==0)
            ref=0;
    }
    return ref; 
}
