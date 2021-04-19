#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> string_s;
	int temp = 1;
	int result = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' ) {
			temp *= 2;
			string_s.push(str[i]);
		}
		else if (str[i] == '[') {
			temp *= 3;
			string_s.push(str[i]);
		}
		else {
			if (str[i] == ')') {
				if (!string_s.empty()&&string_s.top() == '(') {
					if (str[i - 1] == '(') {
						result += temp;
					}
					string_s.pop();
					temp /= 2;
				}
				else {
					cout << 0;
					return 0;
				}
			}
			else if (str[i] == ']') {
				if (!string_s.empty() && string_s.top() == '[') {
					if (str[i - 1] == '[') {
						result += temp;
					}
					string_s.pop();
					temp /= 3;
				}
				else {
					cout << 0;
					return 0;
				}
			}
		}
	}
	if (string_s.empty()) {
		cout << result;
	}
	else {
		cout << 0;
	}
	return 0;
}
