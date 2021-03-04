#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N, M;
const int HOLE = 'H' - '0';
int dir[][4] = {
	//dy,dx
	{0,1}, {1,0}, {0,-1}, {-1,0}
};
bool Check(int x, int y) {
	return (x >= 0 && x < M) && (y >= 0 && y < N);
}

bool is_loop=false;
int solve(vector<vector<int>>& board, vector<vector<int>>& dp, int pre_x, int pre_y, vector<vector<bool>> &visited) {
	if (!Check(pre_x, pre_y)||board[pre_y][pre_x]==HOLE) return 0;
	if (visited[pre_y][pre_x]) {
		is_loop = true;
		return 1;
	}
	if (dp[pre_y][pre_x]) return dp[pre_y][pre_x];
	visited[pre_y][pre_x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = pre_x + board[pre_y][pre_x] * dir[i][1];
		int ny = pre_y + board[pre_y][pre_x] * dir[i][0];
		dp[pre_y][pre_x] = max(dp[pre_y][pre_x], solve(board, dp, nx, ny, visited)+1);
	}
	visited[pre_y][pre_x] = false;
	return dp[pre_y][pre_x];
}

int main() {
	string str;
	vector<vector<int>> board,dp;
	vector<vector<bool>> visited;
	cin >> N >> M;
	board.resize(N);
	dp.resize(N);
	visited.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> str;
		dp[i].resize(M, 0);
		visited[i].resize(M, false);
		for (int j = 0; j < M; j++) {
			board[i].push_back(str[j] - '0');
		}
	}
	int ans = solve(board, dp, 0, 0, visited);
	if (is_loop) {
		printf("-1");
	}
	else {
		printf("%d", ans);
	}
	return 0;
}