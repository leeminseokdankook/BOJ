#include <cstdio>
using namespace std;

int main()
{
    int n;
    bool isOdd=true;
    scanf("%d", &n);
    isOdd=n&1;
    if((isOdd==false&&n%6!=2)||(isOdd==true&&(n-1)%6!=2))
    {
        if(isOdd) n--;
        for(int i=1;i<=n/2;++i)
        {
            printf("%d\n",i*2);
        }
        for(int i=1;i<=n/2;++i)
        {
            printf("%d\n", i*2-1);
        }
        if(isOdd)
        {
            printf("%d", n+1);
        }
    }
    else if((isOdd==false&&n/6!=0)||(isOdd==true&&(n-1)/6!=0))
    {
        if(isOdd) n--;
        for(int i=2;i<=n;i+=2)
        {
            printf("%d\n", 1+(i+(n>>1)-3)%n);
        }
        for(int i=n;i>=1;i-=2)
        {
            printf("%d\n", n-(i+(n>>1)-3)%n);
        }
        if(isOdd)
        {
            printf("%d", n+1);
        }
    }
    return 0;
}
