#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const int MAX=numeric_limits<int>::max();

int solve(int left, int right, vector<vector<int>>* dp, vector<int>& weight_sum, vector<int>& dist, int n, int flag){
    int& ref=dp[flag][left][right];
    if(ref!=MAX){
        return ref;
    }
    if(left==1&&right==n){
        return ref=0;
    }
    int position=flag==1?right:left;
    int turn_on=weight_sum[n]-weight_sum[right]+weight_sum[left-1];
    if(left-1>=1){
        ref=min(ref, solve(left-1,right, dp,weight_sum,dist,n,0)+turn_on*(dist[position]-dist[left-1]));
    }
    if(right+1<=n){
        ref=min(ref, solve(left, right+1, dp,weight_sum,dist, n,1)+turn_on*(dist[right+1]-dist[position]));
    }
    return ref;
}

int main()
{
    vector<vector<int>> dp[2];
    vector<int> dist, weight_sum;
    int n,m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    dp[0].resize(n+1,vector<int>(n+1,MAX));
    dp[1].resize(n+1,vector<int>(n+1,MAX));
    dist.resize(n+1);
    weight_sum.resize(n+1);
    for(int i=1;i<=n;++i){
        cin>>dist[i]>>weight_sum[i];
        weight_sum[i]+=weight_sum[i-1];
    }
    cout<<solve(m,m,dp,weight_sum,dist,n,0);
    return 0;
}
