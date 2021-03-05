#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt=0,n;
	cin >> n;
	while (n > 0) {
		cnt++;
		n -= cnt;
	}
	if (cnt % 2) {
		cout << 1 - n << '/' << cnt + n;
	}
	else {
		cout << cnt + n << '/' << 1 - n;
	}
	return 0;
}

