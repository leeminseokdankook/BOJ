#include <iostream>
#include <vector>
using namespace std;

long long init(vector<long long>& seg, int l, int r, vector<long long>& v, int index);
long long query(vector<long long>& seg, int l, int r, int start, int end, int index);
long long update(vector<long long>& seg, int l, int r, int k, int diff, int index);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<long long> v,seg;
    int n,m,k,h=0;
    cin>>n>>m>>k;
    m=m+k;
    v.resize(n+1);
    while((1<<h)<=n)h++;
    seg.resize(2<<h);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        update(seg,1,n,i,v[i], 1);
    }
    init(seg,1,n,v,1);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            //b번째 수를 c로 바꿈
            update(seg,1,n,b,c, 1);
             v[b]=c;
        }
        else
        {
            cout<<query(seg, 1,n,b,c,1)<<'\n';
        }
    }
}

long long init(vector<long long>& seg, int l, int r, vector<long long>& v, int index)
{
    if(l==r)
    {
        return seg[index]=v[l]%1000000007;
    }
    int mid=(l+r)>>1;
    return seg[index]=init(seg,l,mid,v,index<<1)*init(seg,mid+1,r,v,(index<<1)|1)%1000000007;
}

long long update(vector<long long>& seg, int l, int r, int k, int diff, int index)
{
    if(r<k||l>k)
    {
        return seg[index];
    }
    if(l==r)
    {
        if(l==k)
        {
            return seg[index]=diff;
        }
        else
        {
            return seg[index];
        }
    }
    int mid=(l+r)>>1;
    return seg[index]=update(seg,l,mid,k,diff,index<<1)*update(seg,mid+1,r,k,diff,(index<<1|1))%1000000007;
}

long long query(vector<long long>& seg, int l, int r, int start, int end, int index)
{
    if(r<start||l>end)
    {
        return 1LL;
    }
    if(start<=l&&r<=end)
    {
        return seg[index];
    }
    int mid=(l+r)>>1;
    return query(seg,l,mid,start,end,index<<1)*query(seg,mid+1,r,start, end,(index<<1)|1)%1000000007;
}
