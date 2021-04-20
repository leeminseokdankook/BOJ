#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	int left = 0;
	int right = k;
	int ans;
	while (left <= right) {
		int mid = (left + right) >> 1;
		long long int cnt = 0LL;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n); //mid보다 작은 수의 개수
		}
		if (cnt < k) {
			left = mid + 1;
		}
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
