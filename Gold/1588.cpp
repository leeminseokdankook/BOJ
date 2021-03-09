#include <iostream>
using namespace std;
using ll=long long;
ll a1,a2,a3;

ll* dp[4][4];
//dp[i][j][k] -> i로 시작해 k초만큼 지났을 때, j의 개수
void solve(int num, ll range, ll s, ll e, ll left, ll right, int t);

int main()
{
    int n, num;
    ll l,r, s=0,e=1;
    cin>>num>>l>>r>>n;
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=3;j++)
        {
            dp[i][j]=new ll[n+1]{0};
        }
    }
    for(int i=1;i<=3;++i)
    {
        dp[i][i][0]=1;
        for(int j=1;j<=n;++j)
        {
            dp[i][1][j]=dp[i][1][j-1]+dp[i][2][j-1]*2;
            dp[i][2][j]=dp[i][1][j-1]+dp[i][2][j-1]+dp[i][3][j-1]*2;
            dp[i][3][j]=dp[i][1][j-1]+dp[i][3][j-1];
        }
    }
    for(int i=1;i<=n;++i)
    {
        e*=3;
    }
    --e;
    solve(num,e+1LL,0,e,l,r,n);
    cout<<a1<<"\n"<<a2<<"\n"<<a3;
    return 0;
}

void solve(int num, ll range, ll s, ll e, ll left, ll right, int t)
{
    if(range==1)
    {
        if(left<=s&&e<=right)
        {
            switch(num)
            {
                case 1:
                    ++a1;
                    break;
                case 2:
                    ++a2;
                    break;
                case 3:
                    ++a3;
                    break;
            }
        }
        return;
    }
    if(right<s||left>e)
    {
        return;
    }
    if(left<=s&&e<=right)
    {
        a1+=dp[num][1][t];
        a2+=dp[num][2][t];
        a3+=dp[num][3][t];
        return;
    }
    ll sub_range=range/3;
    ll s1=s,e1=s1+sub_range-1;
    ll s2=e1+1, e2=s2+sub_range-1;
    ll s3=e2+1, e3=s3+sub_range-1;
    --t;
    switch(num)
    {
        case 1:
            solve(1,sub_range,s1,e1,left,right,t);
            solve(3,sub_range,s2,e2,left,right,t);
            solve(2,sub_range,s3,e3,left,right,t);
            break;
        case 2:
            solve(2,sub_range,s1,e1,left,right,t);
            solve(1,sub_range,s2,e2,left,right,t);
            solve(1,sub_range,s3,e3,left,right,t);
            break;
        case 3:
             solve(2,sub_range,s1,e1,left,right,t);
             solve(3,sub_range,s2,e2,left,right,t);
             solve(2,sub_range,s3,e3,left,right,t);
             break;
    }
}
