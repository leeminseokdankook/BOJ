#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void something(int jump, int add, int* v, int n);
long long int MakeSegment(int* v, long long int* seg, int left, int right, int	next);
long long int Answer(long long int* seg, int left, int right, int index, int l, int r);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int* v;
	vector<int> instruction;
	long long int* seg;
	int n,k;
	cin >> n>>k;
	v = new int[n];
	instruction.resize(k + 1);
	instruction[k] = INT32_MAX;
	for (int i = 0; i < n; i++) {
		v[i] = 0;
	}
	for (int i = 0; i < k; i++) {
		cin >> instruction[i];
	}

	sort(instruction.begin(), instruction.end());
	int temp = instruction[0], count = 1;
	for (int i = 1; i <= k; i++) {
		if (temp == instruction[i]) {
			count++;
		}
		else {
			something(temp,count, v, n);
			count = 1;
			temp = instruction[i];
		}
	}
	int h = 0;
	while ((1 << h) < n) {
		h++;
	}
	h = 2 << h;
	seg = new long long int[h];
	MakeSegment(v, seg, 0, n - 1, 1);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int s, e;
		cin >> s >> e;
		long long int ans = Answer(seg, 0, n - 1, 1, s, e);
		cout << ans;
		cout << '\n';
	}
	delete[] seg;
	delete[] v;
	return 0;
}

void something(int jump,int add, int* v, int n) {
	int i = 0;
	while (i < n) {
		v[i] = v[i] + add;
		i += jump;
	}
}

long long int MakeSegment(int* v, long long int* seg, int left, int right, int index) {
	if (left == right) {
		return seg[index] = (long long int)v[left];
	}
	else {
		int next = index << 1;
		int mid = (left + right) >> 1;
		return seg[index] = MakeSegment(v, seg, left,mid, next) + MakeSegment(v, seg, mid+1, right,next + 1);
	}
}

long long int Answer(long long int* seg, int start, int end, int index, int left, int right) {
	if (left > end || right < start) {
		return 0LL;
	}
	if (left <= start && right >= end) {
		return seg[index];
	}
	int next = index << 1;
	int mid = (start + end) >> 1;
	return Answer(seg, start, mid, next, left, right) + Answer(seg, mid+1, end,next+1, left, right);
}
