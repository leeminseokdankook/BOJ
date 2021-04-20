#include <iostream>
#include <stack>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	char str[51];
	int T;
	cin >> T;
	while (T--) {
		cin >> str;
		stack<char> stack;
		int i;
		for (i = 0; str[i]; i++) {
			if (str[i] == '(') {
				stack.push('(');
			}
			else {
				if (stack.empty()) {
					break;
				}
				else {
					stack.pop();
				}
			}
		}
		if (stack.empty() && str[i] == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
