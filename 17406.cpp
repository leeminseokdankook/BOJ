#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct info
{
	int r, c, s;
}info;
int dir[][2] = {
	1,0,0,1,-1,0,0,-1
};		
//dir[0] -> (아래에서 위로 옮기기)
//dir[1]->	(오른쪽에서 왼쪽으로 옮기기)
//dir[2]->	(위쪽에서 아래로)
//dir[3]->	(왼쪽에서 아래로)
//dir[a][0] -> dy, dir[a][1] -> dx 

vector<info> order;

int solve(vector<vector<int>>& arr, vector<info>& infoes, int K, vector<bool>& is_selected);
void Rotation(vector<vector<int>>& arr, int sy, int sx, int width);
int Answer(vector<vector<int>>& arr);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<int>> arr;
	vector<bool> is_selected;
	vector<info> infoes;
	int N, M, K;
	cin >> N >> M >> K;
	arr.resize(N, vector<int>(M));
	is_selected.resize(K, false);
	for (vector<int>& v : arr) {
		for (int& val : v) {
			cin >> val;
		}
	}
	while (K--) {
		int r, c, s;
		cin >> r >> c >> s;
		r--; c--;
		infoes.push_back({ r,c,s });
	}
	cout << solve(arr, infoes, infoes.size(), is_selected);
	return 0;
}

void Rotation(vector<vector<int>>& arr, int sy, int sx, int width) {
	if (width<=1) {
		return;
	}
	int store_val=arr[sy][sx];			//시작지점 값 저장
	for (int i = 0; i < 4; i++) {
		int dx = dir[i][1], dy = dir[i][0];
		for (int j = 0; j < width - 1; j++) {
			arr[sy][sx] = arr[sy + dy][sx + dx];
			sy += dy;
			sx += dx;
		}
	}
	arr[sy - dir[3][0]][sx - dir[3][1]] = store_val;
	
	Rotation(arr, sy + 1, sx + 1, width - 2);
}

int Answer(vector<vector<int>>& arr) {
	int ret = ~(1<<(sizeof(int)*8-1));
	for (vector<int>& v : arr) {
		int sum = 0;
		for (int& val : v) {
			sum += val;
		}
		ret = sum < ret ? sum : ret;
	}

	return ret;
}

int solve(vector<vector<int>>& arr, vector<info>& infoes, int K, vector<bool>& is_selected) {
	if (order.size() == K) {
		vector<vector<int>> cp = arr;
		for (int i = 0; i < K; i++) {
			info pre = order[i];
			Rotation(cp, pre.r - pre.s, pre.c - pre.s, pre.s * 2 + 1);
		}
		return Answer(cp);
	}
	int ret = INT32_MAX;
	for (int i = 0; i < K; i++) {
		if (is_selected[i]) continue;
		order.push_back(infoes[i]);
		is_selected[i] = true;
		ret = min(ret, solve(arr, infoes, K, is_selected));
		is_selected[i] = false;
		order.pop_back();
	}
	return ret;
}
