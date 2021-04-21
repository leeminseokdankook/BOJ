#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void DFS(vector<int>& num, vector<int>& op, vector<bool>& oper_visited, int n_index, int op_index, int v, int result, int* arr) {
	if (op_index == num.size()-1) {
		arr[0] = max(result, arr[0]);
		arr[1] = min(result, arr[1]);
	}
	else {
		for (int i = 0; i < op.size(); i++) {
			int val = result;
			if (!oper_visited[i]) {
				switch (op[i])
				{
					case 0:
						val += num[n_index];
						break;
					case 1:
						val -= num[n_index];
						break;
					case 2:
						val *= num[n_index];
						break;
					case 3:
						val /= num[n_index];
						break;
				}
				oper_visited[i] = true;
				DFS(num, op, oper_visited, n_index + 1, op_index+1, i, val, arr);
			}
		}
	}
	oper_visited[v] = false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> num, op;
	vector<bool> visied;
	int result[2] = { INT32_MIN, INT32_MAX };
	int N;
	cin >> N;
	num.resize(N);
	op.resize(N - 1);
	visied.resize(N - 1, false);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	int index = 0;
	for (int i = 0; i < 4; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			op[index++] = i;
		}
	}
	DFS(num, op, visied, 1, 0, 0, num[0], result);
	cout << result[0] << "\n" << result[1] << "\n";
	return 0;

}
