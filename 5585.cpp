#include <iostream>
using namespace std;

int main()
{
    int values[]={500,100,50,10,5};
    int money;
    int ans=0;
    cin>>money;
    money=1000-money;
    for(int i=0;i<5&&money>=5;++i)
    {
        ans+=money/values[i];
        money=money%values[i];
    }
    ans+=money;
    cout<<ans;
    return 0;
}
