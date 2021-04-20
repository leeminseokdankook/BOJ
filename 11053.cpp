#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	list<int> l,ans;
	int A,N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		l.push_back(A);
	}
	ans.push_back(0);
	for (auto it = l.begin(); it != l.end(); it++) {
		if (*it > ans.back()) {
			ans.push_back(*it);
		}
		else {
			*lower_bound(ans.begin(), ans.end(), *it)=*it;
		}
	}
	cout << ans.size()-1;
	return 0;
}
