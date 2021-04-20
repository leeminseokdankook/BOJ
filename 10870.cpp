#include <iostream>
using namespace std;

int fibo(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n <= 2) {
		return 1;
	}
	return fibo(n - 1) + fibo(n - 2);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	cout << fibo(n);
	return 0;
}


