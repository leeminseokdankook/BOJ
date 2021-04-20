#include <iostream>
#include <vector>
using namespace std;

long long query(vector<long long>& seg, int l, int r, int start, int end, int index);
long long update(vector<long long>& seg, int l, int r, int k, long long diff, int index);
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
    for(int i=0;i<m;i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            //b번째 수를 c로 바꿈
            update(seg,1,n,b,c-v[b], 1);
             v[b]=c;
        }
        else
        {
            cout<<query(seg, 1,n,b,c,1)<<"\n";
        }
    }
}

long long update(vector<long long>& seg, int l, int r, int k, long long diff, int index)
{
    if(r<k||l>k)
    {
        return seg[index];
    }
    if(l==r)
    {
        if(l==k)
        {
            return seg[index]=seg[index]+diff;
        }
        else
        {
            return seg[index];
        }
    }
    int mid=(l+r)>>1;
    return seg[index]=update(seg,l,mid,k,diff,index<<1)+update(seg,mid+1,r,k,diff,(index<<1|1));
}

long long query(vector<long long>& seg, int l, int r, int start, int end, int index)
{
    if(r<start||l>end)
    {
        return 0LL;
    }
    if(start<=l&&r<=end)
    {
        return seg[index];
    }
    int mid=(l+r)>>1;
    return query(seg,l,mid,start,end,index<<1)+query(seg,mid+1,r,start, end,(index<<1)|1);
}
