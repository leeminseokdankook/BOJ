#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
void hanoi(int from, int by, int to, int n);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	hanoi(1, 2, 3, n);
	cout << v.size() << "\n";
	for (pair<int, int>& p : v) {
		cout << p.first << " " << p.second << "\n";
	}
	return 0;
}

void hanoi(int from, int by, int to, int n) {
	if (n == 1) {
		v.push_back(make_pair(from, to));
	}
	else {
		hanoi(from, to, by, n - 1);
		v.push_back(make_pair(from, to));
		hanoi(by, from, to, n - 1);
	}
}

