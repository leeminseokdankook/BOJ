#include <iostream>
#include <cmath>
using namespace std;

int* col;
bool check(int row);
void DFS(int row, int n);
void solve(int n);
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	col = new int[n + 1];
	solve(n);
	return 0;
}


void DFS(int row, int n){
	if (row == n) {
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		col[row + 1] = i;
		if (check(row + 1)) {
			DFS(row + 1, n);
		}
		else {
			col[row + 1] = 0;
		}
	}
	col[row] = 0;
}

void solve(int n) {
	for (int i = 1; i <= n; i++) {
		col[1] = i;
		DFS(1,n);
	}
	cout << ans;
}

bool check(int row) {
	for (int i = 1; i < row; i++) {
		if (col[i] == col[row])return false;
		if(abs(i-row)==abs(col[i]-col[row])) return false;
	}
	return true;
}

