#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int solve(vector<vector<bool>>& is_connect, int cnt, int N, int H, int row_index);
bool is_end(vector<vector<bool>>& is_connect);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<vector<bool>> leader;
	int N,M,H;
	cin >> N >> M>>H;
	leader.resize(N+1);
	for (vector<bool>& v : leader) {
		v.resize(H+1, false);
		v[0] = true;
	}
	while (M > 0) {
		int a, b;
		cin >> a >> b;
		leader[b][a]=true;
		M--;
	}
	int ans = solve(leader, 0, N, H, 1);
	if (ans == INT32_MAX) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	return 0;
}

int solve(vector<vector<bool>>& is_connect, int cnt, int N, int H, int row_index) {
	if (cnt > 3) {
		return INT32_MAX;
	}
	if (is_end(is_connect)) {
		return cnt;
	}
	int ret = INT32_MAX;
	for (int row = row_index; row <= H; row++) {
		for (int col = 1; col <= N-1; col++) {
			if (is_connect[col][row]) continue;
			if (col-1>0&&is_connect[col - 1][row]) continue;
			if (is_connect[col + 1][row]) continue;
			is_connect[col][row] = true;
			ret = min(ret, solve(is_connect, cnt+1, N, H, row));
			is_connect[col][row] = false;
		}
	}
	return ret;
}

bool is_end(vector<vector<bool>>& is_connect) {
	for (int i = 1; i < is_connect.size(); i++) {
		int pre = i;
		for (int row = 1; row < is_connect[0].size(); row++) {
			if (is_connect[pre][row]) pre += 1;
			else if (pre-1>0&&is_connect[pre - 1][row]) pre -= 1;
		}
		if (pre != i) {
			return false;
		}
	}
	return true;
}
