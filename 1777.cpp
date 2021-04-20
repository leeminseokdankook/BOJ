#include <iostream>
#include <vector>
using namespace std;

int CreateSegment(int s, int e ,vector<int>& seg, int index=1)
{
    if(s==e)
    {
        return seg[index]=1;
    }
    int mid=(s+e)>>1;
    return seg[index]=(CreateSegment(s,mid,seg,index<<1)+CreateSegment(mid+1,e,seg,(index<<1)|1));
}

int query(int s, int e, vector<int>& seg, int rank, int index=1)
{
    --seg[index];
    if(s==e)
    {
        return s;
    }
    int mid=(s+e)>>1;
    int left=seg[index<<1];
    if(left>=rank)
    {
        return query(s,mid, seg,rank,index<<1);
    }
    else
    {
        return query(mid+1,e,seg,rank-left,(index<<1)|1);
    }
}

int main()
{
    int n;
    vector<int> inversion, seg,ans;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    inversion.resize(n+1);
    seg.resize(4*n);
    ans.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>inversion[i];
    }
    CreateSegment(1,n,seg);
    for(int i=n;i>0;--i)
    {
        ans[query(1,n,seg,i-inversion[i])]=i;
    }
    for(int i=1;i<=n;++i)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
