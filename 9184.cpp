#include <cstdio>

int dp[21][21][21];

int main()
{
    for(int i=0;i<=20;++i)
    {
        for(int j=0;j<=20;++j)
        {
            for(int k=0;k<=20;++k)
            {
                if(i==0||j==0||k==0)
                {
                    dp[i][j][k]=1;
                }
                else if(i<j&&j<k)
                {
                    dp[i][j][k]=dp[i][j][k-1]+dp[i][j-1][k-1]-dp[i][j-1][k];
                }
                else
                {
                    dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k]+dp[i-1][j][k-1]-dp[i-1][j-1][k-1];
                }
            }
        }
    }
    while(true)
    {
        int a,b,c;
        scanf("%d %d %d", &a,&b,&c);
        if(a==-1&&b==-1&&c==-1)
        {
            break;
        }
        printf("w(%d, %d, %d) = ",a,b,c);
        if(a<=0||b<=0||c<=0)
        {
            printf("1\n");
        }
        else if(a>20||b>20||c>20)
        {
            printf("%d\n",dp[20][20][20]);
        } 
        else
        {
            printf("%d\n",dp[a][b][c]);
        }
    }
    return 0;
}
