#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	string ans = "";
	stack<int> st;
	int max_num = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		if (max_num < val) {
			for (int x = max_num + 1; x <= val; x++){
				st.push(x);
				ans += "+\n";
			}
		}
		else {
			if (st.top() != val) {
				cout << "NO\n";
                return 0;
			}
		}
		st.pop();
		ans += "-\n";
		if (max_num < val) {
			max_num = val;
		}
	}
	cout << ans;
	return 0;
}
