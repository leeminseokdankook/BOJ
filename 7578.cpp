#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 
백준 7578

seg[index]=[start:end] 구간에 연결 되어 있는 간선 수


*/
void update(int l, int r, vector<long long>& seg, int num, int index);
long long query(int l, int r, vector<long long>& seg, int start, int end, int index);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, h=0, num;
    long long ans = 0LL;
    vector<int> A, B(1000001);
    vector<long long> seg;
    cin >> n;
    while ((1 << h) <= n)h++;
    seg.resize(1 << (h + 1));
    A.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        B[num] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        ans += query(1, n, seg, B[A[i]], n, 1);
        update(1, n , seg, B[A[i]], 1);
    }   
    cout << ans;
    return 0;
}

void update(int l, int r, vector<long long>& seg, int num, int index)
{
    if (l > num || r < num)
    {
        return;
    }
    if (l==r)
    {
        seg[index] = 1LL;
        return;
    }
    int mid = (l + r) >> 1;
    update(l, mid, seg, num, index << 1);
    update(mid + 1, r, seg, num, (index << 1) | 1);
    seg[index] = seg[index << 1] + seg[(index << 1) | 1];
}

long long query(int l, int r, vector<long long>& seg, int start, int end, int index)
{
    if (l > end || r < start)
    {
        return 0LL;
    }
    if (start <= l && r <= end)
    {
        return seg[index];
    }
    int mid = (l + r) >> 1;
    return query(l, mid, seg, start, end, index << 1) + query(mid + 1, r, seg, start, end, (index << 1) | 1);
}
