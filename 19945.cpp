#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<1;
    }
    else
    {
        for(int i=32;i>=1;--i)
        {
            if(n&(1<<(i-1)))
            {
                cout<<i;
                break;
            }
        }
    }
    return 0;
}
