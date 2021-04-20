#include <iostream>
#include <stack>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	stack<int> st;
	unsigned int ans = 0;
	int n;
	cin >> n;
	while (n--) {
		int val;
		cin >> val;
		if (val) {
			st.push(val);
		}
		else {
			st.pop();
		}
	}
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	cout << ans;
	return 0;
}
