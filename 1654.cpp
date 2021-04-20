#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<long long int> v;
	long long int N,right=~(1LL<<(sizeof(long long int)*8-1)), left = 0,ans=0, K;
	cin >> K>>N;
	v.resize(K);
	for (long long int& x : v) {
		cin >> x;
	}
	while (left <= right) {
		long long int mid = (left + right)>>1,sum=0;
		for (long long int x : v) {
			sum += x / mid;
		}
		if (sum >= N) {
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
