#include <iostream>
using namespace std;

int main() {
	int all = ~(1 << 21), empty = 0;
	int val = 0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string inst;
	int x;
	int M;
	cin >> M;
	while (M--) {
		cin >> inst;
		if (inst.compare("add") == 0) {
			cin >> x;
			val |= 1 << x;
		}
		else if (inst.compare("remove") == 0) {
			cin >> x;
			val &= ~(1 << x);
		}
		else if (inst.compare("toggle") == 0) {
			cin >> x;
			val ^= 1 << x;
		}
		else if (inst.compare("check") == 0) {
			cin >> x;
			cout << (bool)(val & (1 << x))<<'\n';
		}
		else if (inst.compare("all") == 0) {
			val = all;
		}
		else {
			val = empty;
		}
	}
	return 0;
}
