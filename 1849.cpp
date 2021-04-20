#include <iostream>
#include <vector>
using namespace std;

int init(int l, int r, vector<int>& seg, int index=1);
int query(int l, int r, int cnt, vector<int>& seg, int index=1);
int main()
{
    int n;
    vector<int> cnts,seg,ans;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cnts.resize(n+1);
    ans.resize(n+1);
    seg.resize(4*n);
    for(int i=1;i<=n;i++)
    {
        cin>>cnts[i];
    }
    init(1,n,seg);
    for(int i=1;i<=n;i++)
    {
        int index=query(1,n,cnts[i]+1, seg);
        ans[index]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}

int init(int l, int r, vector<int>& seg, int index)
{
    if(l==r)
    {
        return seg[index]=1;
    }
    int mid=(l+r)>>1;
    return seg[index]=init(l, mid, seg,index<<1)+init(mid+1, r, seg, (index<<1)|1);
}

int query(int l, int r, int cnt, vector<int>& seg, int index)
{
    seg[index]--;
    if(l==r)
    {
        return l;
    }
    int left_cnt=seg[index<<1];
    int mid=(l+r)>>1;
    if(cnt<=left_cnt)
    {
        return query(l,mid, cnt, seg, index<<1);
    }
    else
    {
        return query(mid+1, r, cnt-left_cnt,  seg, (index<<1)|1);
    }
}
