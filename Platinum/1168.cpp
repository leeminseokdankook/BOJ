#include <vector>
#include <iostream>
using namespace std;

int InitSeg(int l, int r, vector<int>& seg, int index);
int Query(int l, int r, vector<int>& seg, int index, int k);

int main()
{
	int n, k, count, index=1;
	vector<int> seg,ans;

	cin >> n >> k;
	count = n;
	seg.resize(n << 2);
	InitSeg(1, n, seg, 1);
	for(int i=n;i>0;--i)
	{
		//i-> 사람수
		index += (k - 1);
		if (index % i == 0)
		{
			index = i;
		}
		else
		{
			index = index % i;
		}
		ans.push_back(Query(1, n, seg, 1, index));
	}
	cout << "<";
	for (int i = 0; i < ans.size() - 1; ++i)
	{
		cout << ans[i] << ", ";
	}
	cout << ans.back() << ">";
	return 0;
}

int InitSeg(int l, int r, vector<int>& seg, int index)
{
	if (l == r)
	{
		return seg[index] = 1;
		
	}
	int left = index << 1;
	int right = left | 1;
	int mid = (l + r) >> 1;
	return seg[index] = (InitSeg(l, mid, seg, left) + InitSeg(mid + 1, r, seg, right));
}

int Query(int l, int r, vector<int>& seg, int index, int k)
{
	--seg[index];
	if (l == r)
	{
		return l;
	}
	int mid = (l + r) >> 1;
	int left_index = index << 1;
	int right_index = left_index | 1;
	int left_cnt = seg[index << 1];
	if (left_cnt >= k)
	{
		return Query(l, mid, seg, left_index, k);
	}
	else
	{
		return Query(mid+1, r, seg, right_index, k - left_cnt);
	}
}
