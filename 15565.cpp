#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k,ans=INT32_MAX;
	list<int> q;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		if (v == 1) {
			q.push_back(i);
			if (q.size() == k) {
				int len = q.back() - q.front() + 1;
				ans = ans > len ? len : ans;
				q.pop_front();
			}
		}
	}
	if (ans==INT32_MAX) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	return 0;
}
