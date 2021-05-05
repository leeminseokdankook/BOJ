#include <vector>
#include <iostream>

using namespace std;
using ll = long long;

ll Init_segmant(vector<ll>& arr, vector<ll>& seg, int left, int right, int tree_index = 1);
ll Update(vector<ll>& seg, int left, int right, vector<ll>& lazy, int start_idnex, int end_index, ll& add, int tree_index = 1);
void Update_lazy(vector<ll>& lazy, int left, int right, int tree_index,vector<ll>& seg);
ll Query(vector<ll>& seg, int left, int right, 
    vector<ll>& lazy, int start_idnex, int end_index, int tree_index = 1);

int main()
{
    vector<ll> seg, arr, lazy;
    int n, m, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    arr.resize(n + 1);
    lazy.resize(4 * (n + 1));
    seg.resize(4 * (n + 1));
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    Init_segmant(arr, seg, 1, n);
    for (int i = 0; i < m + k; ++i)
    {
        int a,b,c;
        cin >> a;
        switch (a)
        {
        case 1:
            ll d;
            cin >> b >> c >> d;
            Update(seg,1, n, lazy, b, c, d);
            break;
        case 2:
            cin >> b >> c;
            cout << Query(seg, 1, n, lazy, b, c) << "\n";
            break;
        }
    }
    return 0;
}

ll Init_segmant(vector<ll>& arr, vector<ll>& seg, int left, int right, int tree_index )
{
    if (left == right)
    {
        return seg[tree_index] = arr[left];
    }
    int mid = (left + right) >> 1;
    int left_tree_index = tree_index << 1;
    return seg[tree_index] = Init_segmant(arr, seg, left, mid, left_tree_index) 
        + Init_segmant(arr, seg, mid + 1, right,left_tree_index | 1);

}
ll Update(vector<ll>& seg, int left, int right, vector<ll>& lazy,
    int start_index, int end_index, ll& add, int tree_index )
{
    Update_lazy(lazy, left, right, tree_index, seg);
    if (left > end_index || right < start_index)
    {
        return seg[tree_index];
    }
    if (start_index <= left && right <= end_index)
    {
        seg[tree_index] += add * (right - left + 1);
        if (left != right)
        {
            lazy[tree_index << 1] += add;
            lazy[(tree_index << 1) | 1] += add;
        }
        return seg[tree_index];
    }
    int mid = (left + right) >> 1;
    int left_tree = tree_index << 1;
    return seg[tree_index]=Update(seg,left, mid, lazy, start_index, end_index, add, left_tree)+
    Update(seg, mid + 1, right, lazy, start_index, end_index, add, left_tree | 1);
}

ll Query(vector<ll>& seg, int left, int right,
    vector<ll>& lazy, int start_index, int end_index, int tree_index )
{
    Update_lazy(lazy, left, right, tree_index, seg);
    if (left > end_index || right < start_index)
    {
        return 0;
    }
    if (start_index<=left&&right<=end_index)
    {
        seg[tree_index] += lazy[tree_index] * (right-left + 1);
        if (left != right)
        {
            lazy[tree_index << 1] += lazy[tree_index];
            lazy[(tree_index << 1)|1] += lazy[tree_index];
        }
        lazy[tree_index] = 0;
        return seg[tree_index];
    }
    int mid = (left + right) >> 1;
    int left_tree = tree_index << 1;
    return Query(seg, left, mid, lazy, start_index, end_index, left_tree)
        + Query(seg, mid + 1, right, lazy, start_index, end_index, left_tree | 1);
}

void Update_lazy(vector<ll>& lazy, int left, int right,int tree_index, vector<ll>& seg)
{
    if (lazy[tree_index] == 0LL)return;
    seg[tree_index] += (lazy[tree_index] * (right - left + 1));
    if (right != left)
    {
        lazy[tree_index << 1] += lazy[tree_index];
        lazy[(tree_index << 1) | 1] += lazy[tree_index];
    }
    lazy[tree_index] = 0;
}
