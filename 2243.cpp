#include <iostream>
#include <vector>
#include <algorithm>
#define KINDOFCANDY 1000000
using namespace std;

/*
백준 2243

*/

void update(vector<int>& tree, int l, int r, int rank, int diff, int index);
int query(vector<int>& tree, int l, int r, int k, int index);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, h=0;
    vector<int> tree;
    while ((1 << h) <= KINDOFCANDY)h++;
    tree.resize(1 << (h+1));
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int instr;
        cin >> instr;
        if (instr == 1)
        {
            int k, rank;
            cin >> k;
            rank = query(tree, 1, KINDOFCANDY, k, 1);
            cout << rank << '\n';
            update(tree,1, KINDOFCANDY, rank, -1, 1);
        }
        else {
            int rank, diff;
            cin >> rank >> diff;
            update(tree, 1, KINDOFCANDY, rank, diff, 1);
        }
    }
    return 0;
}

void update(vector<int>& tree, int l, int r, int rank, int diff, int index)
{
    /*
    tree[index]=맛의 범위가 [l,r] 일때 해당 구간에 있는 총 사탕 수
    */
    tree[index] += diff;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (mid < rank)
    {
        update(tree, mid + 1, r, rank, diff, (index << 1) | 1);
    }
    else {
        update(tree, l, mid, rank, diff, index << 1);
    }
}
int query(vector<int>& tree, int l, int r, int k, int index)
{
    /*
    [l,r]구간을 중간값 mid로 나눔
    [l, mid] 구간의 총 사탕 수가 k이상 k번째 로 맛있는 사탕은 왼쪽에 있음
    k보다 적으면 [mid+1, r]구간에 있음
    */
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) >> 1,
        left_index = index << 1;
    if (tree[left_index] < k)
    {
        //왼쪽이 k보다 적음
        k = k - tree[left_index];  
        return query(tree, mid + 1, r, k, left_index | 1);
    }
    else {
        return query(tree, l, mid, k, left_index);
    }
}
