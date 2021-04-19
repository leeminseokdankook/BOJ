#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int val, max_ans = INT32_MIN, index=1;
	for (int i = 1; i <= 9;i++) {
		cin >> val;
		if (val > max_ans) {
			index = i;
			max_ans = val;
		}
	}
	cout << max_ans << "\n";
	cout<< index;
	return 0;
}

