#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
using matrix=vector<vector<ll>>;

const ll MOD=1e9+7;

matrix operator*(matrix& m1,matrix& m2);

int main()
{
    matrix ans={{1LL,0LL},{0LL,1LL}};
    matrix mul={{4LL,-1LL},{1LL,0LL}};
    matrix get_ans={{1LL,0LL},{1LL,0LL}};
    ll n;
    cin>>n;
    if(n&1LL)
    {
        cout<<0;
    }
    else
    {
        n=n>>1;
        while(n)
        {
            if(n&1LL)
            {
                ans=ans*mul;
            }
            mul=mul*mul;
            n=n>>1;
        }
        ans=ans*get_ans;
        cout<<ans[0][0];
    }
    return 0;
}

matrix operator*(matrix& m1,matrix& m2)
{
    matrix ret(2,vector<ll>(2,0LL));
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            for(int k=0;k<2;++k)
            {
                ret[i][j]+=(m1[i][k]*m2[k][j])%MOD;
                ret[i][j]+=MOD;
                ret[i][j]%=MOD;
            }
        }
    }
    return ret;
}
