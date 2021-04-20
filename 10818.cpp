#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, val, max_ans=INT32_MIN, min_ans=INT32_MAX;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> val;
		max_ans = max(val, max_ans);
		min_ans = min(val, min_ans);
	}
	cout << min_ans << " " << max_ans;
	return 0;
}

