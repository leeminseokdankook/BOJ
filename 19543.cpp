#include <iostream>
#include <vector>
using namespace std;
using ll=long long;

int main()
{
    int n,m,k, index;
    ll s,e,ans=0; //s is index of start 'U', e is index of end 'U'
    vector<string> blocks;
    string batch;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    blocks.resize(k);
    for(int i=0;i<k;++i)
    {
        cin>>blocks[i];
    }
    cin>>batch;
    s=0;e=m-1;
    index=batch.back()-'A';
    for(int i=m-2;i>=0;--i)
    {
        if(blocks[index][i]=='U')
        {
            s=i+1;
            break;
        }
    }
    ans+=(e-s)+1LL;
    for(int row=n-2;row>=0;--row)
    {
        index=batch[row]-'A';
        while(e>=0&&blocks[index][e]!='U')
        {
            --e;
        }
        if(e<0)break;
        --s;
        while(s>=0&&blocks[index][s]!='U')
        {
            --s;
        }
        if(s<0)
        {
            s=0;
        }
        else
        {
            s=s+1;
        }
        ans+=(e-s)+1LL;
    }
    cout<<ans;
    return 0;
}
