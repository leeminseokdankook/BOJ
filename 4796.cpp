#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int l,p,v,i=0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(true)
    {
        cin>>l>>p>>v;
        if(l==0)break;
        ++i;
        cout<<"Case "<<i<<": "<<(v/p)*l+min(v%p, l)<<"\n";
    }
    return 0;
}
