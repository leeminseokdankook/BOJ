#include <iostream>
#include <cstring>
using namespace std;

void solve(bool*, int cnt, int n, int maxi, int* out_put);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool* is_pick;
	int* out_put;
	int n, c;
	cin >> n >> c;
	is_pick = new bool[n + 1];
	out_put = new int[c];
	memset(is_pick, false, sizeof(bool) * (n + 1));
	solve(is_pick, 0, n,c,out_put);
	delete[] is_pick;
	delete[] out_put;
	return 0;
}

void solve(bool* is_pick, int cnt, int n, int maxi, int* out_put) {
	if (cnt == maxi) {
		for (int i = 0; i < cnt; i++) {
			cout << out_put[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!is_pick[i]) {
			is_pick[i] = true;
			out_put[cnt] = i;
			solve(is_pick, cnt + 1, n, maxi, out_put);
			is_pick[i] = false;
		}
	}
}

