#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	long long int ans = 0;
	long long int sum = 0;
	map<long long int, long long int> m;
	m[0] = 1;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		long long int val;
		cin >> val;
		sum += val;
		if (m[sum - k] > 0) {
			ans += m[sum - k];
		}
		m[sum]++;
	}
	cout << ans;
	return 0;
}
