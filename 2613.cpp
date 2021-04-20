#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int* marbles, * groups, N, M, left, right, ans = INT32_MAX, group_res=1;
	cin >> N >> M;
	marbles = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> marbles[i];
	}
	left = 0; right = (100 * N);
	while (left <= right) {
		int mid = (left + right) >> 1, sum = 0, i,group_cnt = 1;
		for (i = 0; i < N; i++) {
			if (marbles[i] > mid) {
				break;
			}
			sum += marbles[i];
			if (sum > mid) {
				sum = marbles[i];
				group_cnt++;
			}
		}
		if (i != N || group_cnt > M)left = mid + 1;
		else {
			right = mid - 1;
			if (mid < ans) {
				group_res = group_cnt;
				ans = mid;
			}
		}
	}
	groups = new int[group_res];
	int sum = 0, cnt = 0, g_index=0;
	for (int i = 0; i < N; i++) {
		sum += marbles[i];
		cnt++;
		if (sum > ans) {
			sum = marbles[i];
			groups[g_index++] = cnt - 1;
			cnt = 1;
		}
	}
	groups[g_index] = cnt;
	cout << ans << '\n';
	int diff = (M - group_res);
	for (int i = 0; i < group_res; i++) {
		while (groups[i] >= 2 && diff > 0) {
			cout << 1 << ' ';
			groups[i]--; diff--;
		}
		cout << groups[i] << ' ';
	}
	return 0;
}

