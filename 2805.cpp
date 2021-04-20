#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<long long int> v;
	long long int N,right = 0, left = 0,ans=0, M;
	cin >> N>>M;
	v.resize(N);
	for (long long int& x : v) {
		cin >> x;
		right = right > x ? right : x;
	}
	while (left <= right) {
		long long int mid = (left + right) / 2;
		long long int sum = 0;
		for (long long int x : v) {
			long long int val = x - mid;
			sum += val > 0 ? val : 0;
		}
		if (sum >= M) {
			if (ans < mid) {
				ans = mid;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
