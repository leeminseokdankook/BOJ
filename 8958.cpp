#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string ans;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ans;
		int sum = 0;
		for (int score = 1, index = 0; index < ans.size(); index++) {
			if (ans[index] == 'O') {
				sum += score;
				score++;
			}
			else {
				score = 1;
			}
		}
		cout << sum<<"\n";
	}
	return 0;
}

