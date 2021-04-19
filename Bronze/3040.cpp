#include <iostream>
using namespace std;

int find(int* data, int* pick, int index, int pick_cnt, int sum);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int arr[9], pick[7];
	for (int& x : arr) {
		cin >> x;
	}
	find(arr, pick, -1, 0, 0);
	for (int x : pick) {
		cout << x << '\n';
	}
	return 0;
}


int find(int* data, int* pick, int index, int pick_cnt, int sum) {
	if (pick_cnt == 7) {
		if (sum == 100) {
			return true;
		}
		else {
			return false;
		}
	}
	if (sum > 100) {
		return false;
	}
	if (9 - index < 7 - pick_cnt) {
		return false;
	}
	for (int i = index + 1; i < 9; i++) {
		pick[pick_cnt] = data[i];
		if (find(data, pick, i, pick_cnt + 1, sum + pick[pick_cnt]))return true;
		pick[pick_cnt] = 0;
	}
	return false;
}
