#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int X, Y;
	cin >> X >> Y;
	int target = (int)((Y * 100) / X);
	int left = 0, right = 1000000001;
	if (target >= 99) {
		cout << -1;
		return 0;
	}
	while (left <= right) {
		int mid = (left + right) >> 1;
		int temp = (int)((Y + (long long int)mid) * 100 / (X + (long long int)mid));
		if (target < temp) {
			right = mid - 1;
		}
		else {
			left = mid +1;
		}
	}
	cout << left;
	return 0;
}
