#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> first_fest(101), second_fest(65);
    int first_price[]=
    {0,5000000,3000000,2000000,500000,300000,100000};
    int rank=1,second_price=5120000;
    int t,a,b;
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=i;j++)
        {
            first_fest[rank++]=first_price[i];
        }
    }
    rank=1;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<(1<<i);j++)
        {
            second_fest[rank++]=second_price;
        }
        second_price>>=1;
    }
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<first_fest[a]+second_fest[b]<<'\n';
    }
    return 0;
}
