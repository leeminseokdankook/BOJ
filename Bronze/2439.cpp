#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = n-1; k > i; k--) {
			cout << " ";
		}
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}
