#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

//input.second -> algorithm_bit_mask
//segment.first -> algorithm_bit and_bit_oper
//segment.second ->         ''      or_bit_oper

pair<int, int>& init_segment_tree(vector<pair<int, int>>& segment, vector<pair<int, int>>& inputs, int left, int right, int tree_index=1);
pair<int, int> query(vector<pair<int, int>>& seg, int left, int right, int front, int back,int k, int tree_index=1);
int algorithm_count(int bit_mask);
int main()
{
    int n,k, d,h=0,left=0,right=0;
    ll ans=0;
    vector<pair<int, int>> arr, seg;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k>>d;
    while((1<<h)<=n)++h;
    arr.resize(n);
    seg.resize(2<<h);
    for(int i=0;i<n;++i)
    {
        arr[i].second=0;
        int M;
        cin>>M>>arr[i].first;
        while(M--)
        {
            int a;
            cin>>a;
            arr[i].second|=(1<<(a-1));
        }
    }
    sort(begin(arr),end(arr));
    init_segment_tree(seg,arr,0,n-1);
    while(right<n)
    {
        if(arr[right].first-arr[left].first<=d)
        {
            auto result=query(seg,0,n-1,left,right,k);
            ll cmp=static_cast<ll>(right-left+1)*(algorithm_count(result.second)-algorithm_count(result.first));
            ans=max(ans,cmp);
            ++right;
        }
        else ++left;
    }
    cout<<ans;
    return 0;
}

pair<int, int>& init_segment_tree(vector<pair<int, int>>& segment, vector<pair<int, int>>& inputs, int left, int right, int tree_index)
{
    if(left==right)
    {
        segment[tree_index].first=segment[tree_index].second=inputs[left].second;
        return segment[tree_index];
    }
    int mid=(left+right)>>1;
    int left_tree_index=(tree_index<<1);
    int right_tree_index=(tree_index<<1)|1;
    auto &left_sub_tree=init_segment_tree(segment,inputs,left,mid,left_tree_index);
    auto &right_sub_tree=init_segment_tree(segment,inputs,mid+1,right,right_tree_index);
    segment[tree_index].first=left_sub_tree.first&right_sub_tree.first;
    segment[tree_index].second=left_sub_tree.second|right_sub_tree.second;
    return segment[tree_index];
}

pair<int, int> query(vector<pair<int, int>>& seg, int left, int right, int front, int back,int k, int tree_index)
{
    if(left>back||right<front)
    {
        return {~(1<<k),0};
    }
    if(front<=left&&right<=back)
    {
        return seg[tree_index];
    }
    int mid=(left+right)>>1;
    int left_tree_index=(tree_index<<1);
    int right_tree_index=(tree_index<<1)|1;
    auto left_tree=query(seg,left,mid,front,back,k,left_tree_index);
    auto right_tree=query(seg,mid+1,right,front,back,k,right_tree_index);
    return {left_tree.first&right_tree.first, left_tree.second|right_tree.second};
}

int algorithm_count(int bit_mask)
{
    int cnt=0;
    while(bit_mask)
    {
        if(bit_mask&1)++cnt;
        bit_mask>>=1;
    }
    return cnt;
}
