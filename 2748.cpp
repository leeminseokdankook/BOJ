#include <iostream>
using namespace std;

long long f[91];
long long fibo(int n)
{
    long long& ref=f[n];
    if(ref!=0)
    {
        return ref;
    }
    if(n==0)
    {
        return ref=0;
    }
    if(n==1)
    {
        return ref=1;
    }
    return ref=fibo(n-1)+fibo(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<fibo(n);
    return 0;
}
