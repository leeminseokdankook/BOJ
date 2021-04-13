#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

/*
풀이 방법
세그먼트 트리를 이용
각 노드는 구간 별로 최댓값, 최솟값을 가짐

*/


int MakeMaxSeg(vector<int>& MaxSeg, vector<int>& arr,int left, int right, int index);
int MakeMinSeg(vector<int>& MainSeg, vector<int>& arr, int left, int right, int index);
int FindMaxSeg(vector<int>& MaxSeg, int left, int right, int index, int a,int b);
int FindMinSeg(vector<int>& MinSeg, int left, int right, int index, int a, int b);
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,height=0;
	vector<int> arr, max_seg, min_seg;
	cin >> n>>m;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	while ((1 << height) <= n)height++;
	max_seg.resize(1 << (height+1));
	min_seg.resize(1 << (height+1), INT32_MAX);
	MakeMaxSeg(max_seg, arr, 0, n - 1, 1);
	MakeMinSeg(min_seg, arr, 0, n - 1, 1);
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout  << FindMinSeg(min_seg, 0, n - 1, 1, a, b)<<' '<< FindMaxSeg(max_seg, 0, n - 1, 1, a, b) << '\n';
	}
	return 0;
}

int MakeMaxSeg(vector<int>& MaxSeg, vector<int>& arr, int left, int right, int index)
{
	if (left == right)
	{
		return MaxSeg[index] = arr[left];
	}
	int mid = (left + right) >> 1;
	return MaxSeg[index] = max(MakeMaxSeg(MaxSeg, arr, left, mid, index << 1), MakeMaxSeg(MaxSeg, arr, mid + 1, right, (index << 1) | 1));
}

int MakeMinSeg(vector<int>& MinSeg, vector<int>& arr, int left, int right, int index)
{
	if (left == right)
	{
		return MinSeg[index] = arr[left];
	}
	int mid = (left + right) >> 1;
	return MinSeg[index] = min(MakeMinSeg(MinSeg, arr, left, mid, index << 1), MakeMinSeg(MinSeg, arr, mid + 1, right, (index << 1) | 1));
}

int FindMaxSeg(vector<int>& MaxSeg, int left, int right, int index, int a, int b)
{
	if (left > b || right < a)
	{
		return 0;
	}
	if (left >= a && right <= b)
	{
		return MaxSeg[index];
	}
	int mid = (left + right) >> 1;
	return max(FindMaxSeg(MaxSeg, left, mid, index << 1, a, b), FindMaxSeg(MaxSeg, mid + 1, right, (index << 1) | 1, a, b));
}

int FindMinSeg(vector<int>& MinSeg, int left, int right, int index, int a, int b)
{
	if (left > b || right < a)
	{
		return INT32_MAX;
	}
	if (left >= a && right <= b)
	{
		return MinSeg[index];
	}
	int mid = (left + right) >> 1;
	return min(FindMinSeg(MinSeg, left, mid, index << 1, a, b), FindMinSeg(MinSeg, mid + 1, right, (index << 1) | 1, a, b));
}
