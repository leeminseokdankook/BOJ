#include <iostream>
using namespace std;

int sum(int n);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	cout << sum(N);
	return 0;
}

int sum(int N) {
	if (N == 1) {
		return N;
	}
	if (!(N % 2)) {
		return (N / 2) * (N / 2) + 2*sum(N / 2);
	}
	else{
		return sum(N - 1) + N;
	}
}
