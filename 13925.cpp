#include <iostream>
#include <vector>
using namespace std;
using ll=long long;

const ll MOD=1e9+7;


//lazies[0] -> mul
//lazies[1] -> add

void update_lazy(vector<ll>& seg, vector<vector<ll>>& lazies, int left, int right, int tree_index);
ll query(vector<ll>& seg,vector<vector<ll>>& lazies, int left, int right, int front, int back, int tree_index=1);
ll update(vector<ll>& seg,vector<vector<ll>>& lazies, ll& mul, ll& add, int left, int right, int front, int back, int tree_index=1);
int main()
{
    vector<vector<ll>> lazies;
    vector<ll> seg;
    int n,m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    seg.resize(4*n);
    lazies.resize(2);
    lazies[0].resize(4*n, 1LL);
    lazies[1].resize(4*n,0);
    for(int i=1;i<=n;++i)
    {
        ll val;
        ll z=1;
        cin>>val;
        update(seg, lazies, z,val, 1,n, i,i);
    }
    cin>>m;
    while(m--)
    {
        int q,x,y;
        cin>>q>>x>>y;
        if(q<=3)
        {
            ll sub;
            ll v;
            cin>>v;
            switch(q)
            {
                case 1:
                    sub=1;
                    update(seg,lazies,sub,v,1,n,x,y);
                    break;
                case 2:
                    sub=0;
                    update(seg,lazies,v,sub,1,n,x,y);
                    break;
                case 3:
                    sub=0;
                    update(seg,lazies,sub,v,1,n,x,y);
                    break;
            }
        }
        else
        {
            cout<<query(seg,lazies,1,n,x,y)<<"\n";
        }
    }
    return 0;
}

void update_lazy(vector<ll>& seg, vector<vector<ll>>& lazies, int left, int right, int tree_index)
{
    if(lazies[0][tree_index]==1LL&&lazies[1][tree_index]==0)return;
    seg[tree_index]*=lazies[0][tree_index];
    seg[tree_index]%=MOD;
    seg[tree_index]+=lazies[1][tree_index]*(right-left+1);
    seg[tree_index]%=MOD;
    if(left!=right)
    {
        for(int i=tree_index<<1;i<=((tree_index<<1)|1);++i)
        {
            lazies[0][i]*=lazies[0][tree_index];
            lazies[0][i]%=MOD;
            lazies[1][i]=(lazies[0][tree_index]*lazies[1][i]%MOD+lazies[1][tree_index])%MOD;
        }
    }
    lazies[0][tree_index]=1;
    lazies[1][tree_index]=0;
}

ll update(vector<ll>& seg,vector<vector<ll>>& lazies, ll& mul, ll& add, int left, int right, int front, int back, int tree_index)
{
    update_lazy(seg,lazies,left,right,tree_index);
    if(right<front||left>back)
    {
        return seg[tree_index];
    }
    if(front<=left&&right<=back)
    {
        lazies[0][tree_index]*=mul;
        lazies[0][tree_index]%=MOD;
        lazies[1][tree_index]*=mul;
        lazies[1][tree_index]%=MOD;
        lazies[1][tree_index]+=add;
        lazies[1][tree_index]%=MOD;
        update_lazy(seg,lazies,left,right,tree_index);
        return seg[tree_index];
    }
    int mid=(left+right)>>1;
    return seg[tree_index]=(update(seg,lazies,mul,add,left,mid,front, back,tree_index<<1)+
        update(seg,lazies,mul,add,mid+1,right,front, back,(tree_index<<1)|1))%MOD;
}

ll query(vector<ll>& seg,vector<vector<ll>>& lazies, int left, int right, int front, int back, int tree_index)
{
    update_lazy(seg,lazies,left,right,tree_index);
    if(right<front||left>back)
    {
        return 0LL;
    }
    if(front<=left&&right<=back)
    {
        return seg[tree_index];
    }
    int mid=(left+right)>>1;
    return (query(seg,lazies,left,mid,front, back,tree_index<<1)+
        query(seg,lazies,mid+1,right,front, back,(tree_index<<1)|1))%MOD;
}
