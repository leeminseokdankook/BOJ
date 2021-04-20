#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool pick(vector<int>& len, vector<int>&picked, int pre_index);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> len, picked;
	for (int i = 0; i < 9; i++) {
		int x;
		cin >> x;
		len.push_back(x);
	}
	sort(len.begin(), len.end());
	pick(len, picked, -1);
	for (int x : picked) {
		cout << x<<'\n';
	}
	return 0;
}

bool pick(vector<int>& len, vector<int>& picked, int pre_index) {
	if (picked.size() == 7) {
		int sum = 0;
		for (int x : picked) {
			sum += x;
		}
		if (sum == 100) {
			return true;
		}
		else {
			return false;
		}
	}
	for (int index = pre_index + 1; index < 9; index++) {
		picked.push_back(len[index]);
		if (pick(len, picked, index)) {
			return true;
		}
		picked.pop_back();
	}
	return false;
}
