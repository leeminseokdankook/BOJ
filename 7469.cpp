#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void update(vector<vector<int>>& seg_tree, int val,int index, int s, int e, int seg_index);
int query(vector<vector<int>>& seg_tree, int i, int j, int x, int s, int e, int seg_index);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> seg_tree;
    int n, val,m;
    cin>>n>>m;
    seg_tree.resize(4*n);
    for(int i=1;i<=n;i++)
    {
        int val;
        cin>>val;
        update(seg_tree, val, i, 1,n, 1);
    }
    for(auto& v:seg_tree)
    {
        sort(v.begin(), v.end());
    }
    while(m--)
    {
        int i,j,k, l,r;
        cin>>i>>j>>k;
        l=-1e9;
        r=1e9;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(query(seg_tree,i,j,mid,1,n,1)<k)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        cout<<l<<"\n";
    }
}

void update(vector<vector<int>>& seg_tree, int val,int index, int s, int e, int seg_index)
{
    if(s>index||e<index)
    {
        return;
    }
    seg_tree[seg_index].push_back(val);
    if(s!=e)
    {
        int mid=(s+e)/2;
        update(seg_tree,val,index,s,mid,seg_index<<1);
        update(seg_tree,val,index,mid+1,e,(seg_index<<1)|1);
    }
}

int query(vector<vector<int>>& seg_tree, int i, int j, int x, int s, int e, int seg_index)
{
    if(e<i||s>j)
    {
        return 0;
    }
    if(i<=s&&e<=j)
    {
        return upper_bound(seg_tree[seg_index].begin(),seg_tree[seg_index].end(), x)
            -seg_tree[seg_index].begin();
    }
    int mid=(s+e)/2;
    return query(seg_tree,i,j,x,s,mid,seg_index<<1)+query(seg_tree,i,j,x,mid+1,e,(seg_index<<1)+1);
}
