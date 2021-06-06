#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int init(vector<int>& arr, vector<int>& seg, int left, int right, int tree_index = 1);
int update(vector<int>& arr,vector<int>& seg, int left, int right, int index, int tree_index = 1);
int query(vector<int>& arr,vector<int>& seg, int left, int right, int start, int end, int tree_index = 1);

int main()
{
	vector<int> seg,arr;
	int n,m;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	seg.resize(n << 2);
	arr.resize(n);
	for (int& ele : arr){
		cin >> ele;
	}
	init(arr, seg, 0, n - 1);
	cin >> m;
	while (m--){
		int a, b, c;
		cin >> a >> b >> c;
		--b;
		if (a == 1){
			arr[b] = c;
			update(arr, seg, 0, n - 1, b);
		}
		else{
			--c;
			cout << query(arr, seg, 0, n - 1, b, c)+1<<"\n";
		}
	}
}

int init(vector<int>& arr, vector<int>& seg, int left, int right, int tree_index){
	if (left == right)
		return seg[tree_index] = left;
	int mid = (left + right) >> 1;
	int array_index_of_left_tree = init(arr, seg, left, mid, tree_index * 2);
	int array_index_of_right_tree = init(arr, seg, mid + 1, right, tree_index * 2 + 1);
	return seg[tree_index] = arr[array_index_of_left_tree] <= arr[array_index_of_right_tree] ? array_index_of_left_tree : array_index_of_right_tree;
}

int update(vector<int>& arr, vector<int>& seg, int left, int right, int index,int tree_index){
	if ((left <= index && index <= right) == false)
		return seg[tree_index];
	if (left == right)
		return seg[tree_index]=left;
	int mid = (left + right) >> 1;
	int array_index_of_left_tree = update(arr, seg, left, mid, index,tree_index * 2);
	int array_index_of_right_tree = update(arr, seg, mid + 1, right, index,tree_index * 2 + 1);
	return seg[tree_index] = arr[array_index_of_left_tree] <= arr[array_index_of_right_tree] ? array_index_of_left_tree : array_index_of_right_tree;
}

int query(vector<int>& arr, vector<int>& seg, int left, int right, int start, int end, int tree_index) {
	if (start<=left && right <= end)
		return seg[tree_index];
	if (left > end || right < start)
		return -1;
	int mid = (left + right) >> 1;
	int array_index_of_left_tree = query(arr,seg, left, mid, start,end, tree_index * 2);
	int array_index_of_right_tree = query(arr, seg, mid+1, right, start, end, tree_index * 2+1);
	if (array_index_of_left_tree == -1 && array_index_of_right_tree == -1)
		return -1;
	if (array_index_of_left_tree == -1)
		return array_index_of_right_tree;
	if (array_index_of_right_tree == -1)
		return array_index_of_left_tree;
	return arr[array_index_of_left_tree] <= arr[array_index_of_right_tree] ? array_index_of_left_tree : array_index_of_right_tree;
}
