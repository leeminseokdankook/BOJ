#include <iostream>
using namespace std;
using ull= unsigned long long;

int main()
{
    ull N;
    cin>>N;
    for(int i=0;i<=63;++i)
    {
        if(N&(1LL<<i))
        {
            cout<<64-i;
            break;
        }
    }
    return 0;
}
