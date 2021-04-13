#include <iostream>
using namespace std;

int main() {
	int* stack, top = -1, n, * heights, *ans;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	stack = new int[n];
	heights = new int[n+1];
	ans = new int[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> heights[i];
	}
	for (int i = 1; i <= n; i++) {
		while (top != -1 && heights[stack[top]] <= heights[i]) {
			top--;
		}
		if (top == -1) {
			ans[i] = 0;
			stack[++top] = i;
		}
		else {
			ans[i] = stack[top];
			stack[++top] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	delete[] ans;
	delete[] heights;
	delete[] stack;
	return 0;
}
