#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> v;
	int N;
	long long int left = 0, right = 0, M,ans=0;
	cin >> N;
	v.resize(N);
	for (int& x : v) {
		cin >> x;
		right = right > x ? right : x;
	}
	cin >> M;	

	while (left <= right) {
		long long int mid = (left + right) >> 1,sum=0LL;
		for (int x : v) {
			sum += (x > mid ? mid : x);
		}
		if (sum <= M) {
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
