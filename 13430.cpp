#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
const ll MOD=1000000007LL;
vector<vector<ll>> MultiplyMatrix(vector<vector<ll>>& m1, vector<vector<ll>>& m2)
{
    vector<vector<ll>> ret;
    if(m1.empty()==true)
    {
        ret=m2;
        return ret;
    }
    //mutiply n*k, k*m matrix
    int m1_row=m1.size();
    int m1_col=m1[0].size();
    int m2_row=m2.size();
    int m2_col=m2[0].size();
    ret.resize(m1_row, vector<ll>(m2_col));
    for(int n=0;n<m1_row;++n)
    {
        for(int m=0;m<m2_col;++m)
        {
            for(int k=0;k<m1_col;++k)
            {
                ret[n][m]+=m1[n][k]*m2[k][m];
                ret[n][m]%=MOD;
            }
        }
    }
    return ret;
}

int main()
{
    vector<vector<ll>> base,a;
    int ans=0;
    int n,k;
    cin>>k>>n;
    if(n==1)
    {
        cout<<1<<"\n";
        return 0;
    }
    base.resize(k+2, vector<ll>(k+2));
    for(int i=0;i<k+2;++i)
    {
        for(int j=0;j<=i;++j)
        {
            base[i][j]=1;
        }
    }
    n--;
    while(n)
    {
        if(n&1)a=MultiplyMatrix(a,base);
        base=MultiplyMatrix(base,base);
        n=n>>1;
    }
    for(int i=0;i<k+2;++i)
    {
        ans+=a[k+1][i];
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}
