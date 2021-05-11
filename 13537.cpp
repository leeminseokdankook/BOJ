#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int>& init_merge_seg(vector<vector<int>>& seg, vector<int>& arr, int l, int r, int index=1)
{
    if(l==r)
    {
        seg[index].push_back(arr[l]);
        return seg[index];
    }
    int mid=(l+r)>>1;
    vector<int>& left=init_merge_seg(seg, arr, l,mid,index<<1);
    vector<int>& right=init_merge_seg(seg, arr, mid+1, r, (index<<1)|1);
    int l_index,r_index;
    //Merge
    for(l_index=0,r_index=0;l_index<left.size()&&r_index<right.size();)
    {
        if(left[l_index]<right[r_index])
        {
            seg[index].push_back(left[l_index++]);
        }
        else
        {
            seg[index].push_back(right[r_index++]);
        }
    }
    while(l_index<left.size())
    {
        seg[index].push_back(left[l_index++]);
    }
    while(r_index<right.size())
    {
        seg[index].push_back(right[r_index++]);
    }
    return seg[index];
}

int query(vector<vector<int>>& seg, int l, int r, int i, int j,int k, int index=1);
int main()
{
    vector<vector<int>> seg;
    vector<int> arr;
    int n,m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    arr.resize(n+1);
    seg.resize(4*n);
    for(int i=1;i<=n;++i)
    {
        cin>>arr[i];
    }
    init_merge_seg(seg, arr, 1,n);
    cin>>m;
    while(m--)
    {
        int i,j,k;
        cin>>i>>j>>k;
        cout<<query(seg, 1,n,i,j,k)<<"\n";
    }
    return 0;
}

int query(vector<vector<int>>& seg, int l, int r, int i, int j,int k, int index)
{
    if(i>r||j<l)return 0;
    if(i<=l&&r<=j)
    {
        return static_cast<int>(seg[index].end()-upper_bound(begin(seg[index]), end(seg[index]), k));
    }
    int mid=(l+r)>>1;
    return query(seg, l,mid,i,j,k,index<<1)+query(seg,mid+1,r,i,j,k,(index<<1)|1);
}
