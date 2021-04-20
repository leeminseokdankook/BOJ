#include <iostream>
using namespace std;

int ans = 0, black_jack;
;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, *value;
	int ans = 0, black_jack;
	cin >> n>>black_jack;
	value = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (value[i] + value[j] + value[k]<=black_jack&&black_jack - (value[i] + value[j] + value[k]) < black_jack - ans) {
					ans = (value[i] + value[j] + value[k]);	
				}
			}
		}
	}
	cout << ans;
    delete[] value;
	return 0;
}


