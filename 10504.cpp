#include <iostream>
#include <cmath>
using namespace std;
using ll=long long;

bool is_possible(int x, int n);

int main()
{
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        ll N, len, s=0;
        cin>>N;
        if(N&1LL)
        {
            s=(N/2)-1;
            len=2;
        }
        else
        {
            len=N+1;
            for(ll i=2;i*i<=2*N;++i)
            {
                if((N-i*(i+1)/2)%i==0)
                {
                    len=i;
                    break;
                }
            }
            s=(N-len*(len+1)/2)/len;
        }
        if(s<0LL)
        {
            cout<<"IMPOSSIBLE\n";
        }
        else
        {
            cout<<N<<" =";
            for(ll i=1;i<len;++i)
            {
                cout<<" "<<s+i<<" +";
            }
            cout<<" "<<s+len<<"\n";
        }
    }
    return 0;
}
