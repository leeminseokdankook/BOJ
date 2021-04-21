#include <iostream>
#include <vector>
using namespace std;

bool check(int row, int col, int n)
{
    return (row>=0&&row<n&&col<n&&col>=0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<long long>> sum,answer,height;
    int n,m,range;
    cin>>n>>m;
    range=m>>1;
    sum.resize(n,vector<long long>(n));
    answer.resize(n,vector<long long>(n));
    height.resize(n,vector<long long>(n));
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            cin>>height[row][col];
            height[row][col]*=-1;
        }
    }
    for(int start=0;start<m;start++)
    {
       for(int row=0;row<n;row++)
       {
           int sum_row=row+range;
           for(int col=start;col<n;col+=m)
           {
               int sum_col=col+range;
               if(check(sum_row, sum_col, n)==false)break;    
                   sum[sum_row][sum_col]=height[row][col]
                       +(sum_col>=m?sum[sum_row][sum_col-m]:0)
                       +(sum_row>=m?sum[sum_row-m][sum_col]:0)
                       -(sum_row>=m&&sum_col>=m?sum[sum_row-m][sum_col-m]:0);
           }
        }
    }
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            long long area1=(row-1>=0)?sum[row-1][col]:0;
            long long area2=(col>=1)?sum[row][col-1]:0;
            long long area3=(row-1>=0&&col-1>=0)?sum[row-1][col-1]:0;
            cout<<(sum[row][col]-(area1+area2-area3))<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
