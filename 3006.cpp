#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int InitSeg(int l, int r, vector<int>& seg, int index = 1)
{
	if (l == r)
	{
		return seg[index] = 1;
	}
	int mid = (l + r) >> 1;
	return seg[index] = (InitSeg(l, mid, seg, index << 1)+InitSeg(mid + 1, r, seg, (index << 1) | 1));
}

int query(int l, int r, vector<int>& seg, int s, int e, int index = 1);
//[s,e]까지의 숫자 남아 있는 숫잗들의 개수
void update(int l, int r, vector<int>& seg, int target, int index = 1);
int main()
{
	int n, f, e;
	vector<int> seg;
	vector<pair<int, int>> arr;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	arr.resize(n);
	seg.resize(4 * n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(begin(arr), end(arr));
	InitSeg(0, n - 1, seg);
	f = 0; e = n - 1;
	for (int i = 0; i < n; ++i)
	{
		//(i+1) 번째 수행
		if ((i & 1) == 0)
		{
			//홀수번째 단계 수행
			cout << query(0, n - 1, seg, 0, arr[f].second)-1<<"\n";
			update(0, n-1, seg, arr[f].second);
			++f;
		}
		else
		{
			cout << query(0, n - 1, seg, arr[e].second, n-1)-1 << "\n";
			update(0, n - 1, seg, arr[e].second);
			--e;
		}
	}
	return 0;
}

int query(int l, int r, vector<int>& seg, int s, int e, int index)
{
	if (l>e||r<s)
	{
		return 0;
	}
	else if (s<=l && r <= e)
	{
		return seg[index];
	}
	int mid = (l + r) >> 1;
	return query(l, mid, seg, s, e, index << 1) + query(mid + 1, r, seg, s, e, (index << 1) | 1);
}

void update(int l, int r, vector<int>& seg, int target, int index)
{
	seg[index]--;
	if (l == r)
	{
		return;
	}
	int mid = (l + r) >> 1;
	if (target > mid)
	{
		update(mid + 1, r, seg, target, (index << 1)|1);
	}
	else
	{
		update(l, mid, seg, target, (index << 1));
	}
}
