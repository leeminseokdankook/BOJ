#include <iostream>
#include <algorithm>
using namespace std;


/*
0 1 2 3 4
0 1 0 0 1
0 1 0 1 0
0 0 1 1 0
0 0 1 0 1
*/
int dp[501][5];

int solve(int cur, int state)
{
    if(cur<0)return 0;
    int& ref=dp[cur][state];
    if(ref!=-1)return ref;
    if(cur==0) return state==0;
    switch(state)
    {
        case 0:
            ref=solve(cur-1, 0)+solve(cur-2,0)+solve(cur-1,3)+solve(cur-1,1)+solve(cur-1,2);
            break;
        case 1:
            ref=solve(cur-1,2)+solve(cur-1,0);
            break;
        case 2:
            ref=solve(cur-1,0)+solve(cur-1,1);
            break;
        case 3:
            ref=solve(cur-1,4)+solve(cur-1,0);
            break;
        case 4:
            ref=solve(cur-1,3);
            break;
    }
    return ref;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<=500;i++)
    {
        for(int j=0;j<5;++j)
        {
            dp[i][j]=-1;
        }
    }
    while(t--)
    {
        int n;
        cin>>n;
        cout<<solve(n,0)<<"\n";
    }
    return 0;
}
