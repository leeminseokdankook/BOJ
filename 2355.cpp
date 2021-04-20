#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int A, B;
	cin >> A >> B;
	if (A > B) {
		swap(A, B);
	}
	cout << (A + B) * (B - A + 1) / 2;
	return 0;
}
