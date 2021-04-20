#include <iostream>
#include <vector>
using namespace std;

int solve(int w, int h, vector<vector<int>>& dp);

int main()
{
    vector<vector<int>> dp;
    int n,m,width, height;
    cin>>n>>m;
    width=max(n,m);
    height=min(n,m);
    dp.resize(width+1, vector<int>(height+1, INT32_MAX));
    cout<<solve(width,height,dp);
    return 0;
}

int solve(int w, int h, vector<vector<int>>& dp)
{
    //길이가 짧은 쪽을 높이로 설정
    int height=min(w,h);
    int width=max(w,h);
    int& ref=dp[width][height];
    if(ref!=INT32_MAX)
    {
        return ref;
    }
    if(width%height==0)
    {
        return ref=width/height;
    }
    if(width>height*3)
    {
        return ref=1+solve(width-height, height, dp);
    }
    int cut_h=height/2;
    int cut_w=width/2;
      //가로 방향으로 칼 긋기
    for(int len=1;len<=cut_h;len++)
    {
        ref=min(ref, solve(width, height-len, dp)
               +solve(width, len,dp));
    }
    //세로 방향으로 칼 긋기
    for(int len=1;len<=cut_w;len++)
    {
        ref=min(ref, solve(width-len, height, dp)
               +solve(len, height, dp));
    }
    return ref;
}
