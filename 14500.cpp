#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dir[][2] = { {1,0},{0,1}, {-1,0}, {0,-1} };
int dfs(int x, int y, vector<vector<int>>& board, vector<vector<bool>>& visited, int len);
int T_shape(int x, int y, int N, int M, vector<vector<int>>& board);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, ans=-1;
	vector<vector<int>> board;
	vector<vector<bool>> visited;
	cin >> N >> M;
	board.resize(N);
	visited.resize(N);
	for (int row = 0; row < N; row++) {
		board[row].resize(M);
		visited[row].resize(M, false);
		for (int col = 0; col < M; col++) {
			cin >> board[row][col];
		}
	}
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			visited[row][col] = true;
			ans=max(dfs(col, row, board, visited, 1),ans);
			ans = max(T_shape(col, row, N, M, board), ans);
			visited[row][col] = false;
		}
	}
	cout << ans;
	return 0;
}

int dfs(int x, int y, vector<vector<int>>& board, vector<vector<bool>>& visited, int len) {
	if (len == 4) {
		return board[y][x];
	}
	int ans = -1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][1];
		int nx = x + dir[i][0];
		if (((ny < board.size()) && (ny > -1) && (nx < board[ny].size()) && (nx > -1)) && !visited[ny][nx]) {
			visited[ny][nx] = true;
			ans = max(ans, dfs(nx, ny, board, visited, len + 1) + board[y][x]);
			visited[ny][nx] = false;
		}
	}
	return ans;
}

int T_shape(int x, int y, int N, int M, vector<vector<int>>& board) {
	int ans = -1;
	//ㅗ
	if (x > 0 && x < (M - 1) && y>0) {
		ans = max(ans, board[y][x] + board[y - 1][x] + board[y][x - 1] + board[y][x + 1]);
	}
	//ㅜ
	if (x >= 1 && x < (M - 1) && y < (N - 1)) {
		ans = max(ans, board[y][x] + board[y + 1][x] + board[y][x - 1] + board[y][x + 1]);
	}
	//ㅏ
	if (x < (M - 1) && y>0 && y < (N - 1)) {
		ans = max(ans, board[y][x] + board[y + 1][x] + board[y - 1][x] + board[y][x + 1]);
	}
	//ㅓ
	if (x > 0 && y > 0 && y < (N - 1)) {
		ans = max(ans, board[y][x] + board[y][x - 1] + board[y + 1][x] + board[y - 1][x]);
	}
	return ans;
}
