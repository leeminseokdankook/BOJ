#include <iostream>
#include <vector>
using namespace std;

int dir[5][2] = { {0,0}, {1,0},{-1,0},{0,-1},{0,1} };//dx, dy

int ReversDir(int pre_dir);
int Solve(vector<vector<int>>& state, vector<pair<pair<int, int>, int>>& chesses);
void Move(vector<vector<int>>& state_board, vector<vector<vector<int>>>& board, vector<pair<pair<int, int>, int>>& chesses, int move_cnt, int state ,int i); //
int Counting_Move_Chesses(vector<vector<vector<int>>>& board, int chess_num, pair<pair<int, int>, int>& chess_info);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<vector<int>> state;
	vector<pair<pair<int, int>, int>> chesses;//{position, dir};
	int N, K;
	cin >> N >> K;
	state.resize(N+1);
	for (int row = 1; row <= N; row++) {
		state[row].resize(N + 1);
		for (int col = 1; col <= N; col++) {
			cin >> state[row][col];
		}
	}
	chesses.resize(K + 1);
	for (int i = 1; i <= K; i++) {
		int x, y, dir;
		cin >> y >> x >> dir;
		chesses[i] = { {x,y},dir };
	}
	cout << Solve(state, chesses);
	return 0;
}

int Solve(vector<vector<int>>& state, vector<pair<pair<int, int>, int>>& chesses) {
	vector<vector<vector<int>>> board;
	vector<vector<vector<vector<bool>>>> visited;//[ny][nx][i][i_dir]
	int N = state.size() - 1, K = chesses.size() - 1, turn = 1;
	board.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		board[i].resize(N + 1);
		visited[i].resize(N + 1);
		for (int j = 1; j <= N; j++) {
			visited[i][j].resize(K + 1);
			for (int k = 1; k <= K; k++) {
				visited[i][j][k].resize(5, false);
			}
		}
	}

	for (int i = 1; i <= K; i++) {
		board[chesses[i].first.second][chesses[i].first.first].push_back(i);
		visited[chesses[i].first.second][chesses[i].first.first][i][chesses[i].second] = true;
	}
	bool flag = false;
	while (turn != 1001) {
		for (int i = 1; i <= K; i++) {
			int ny = chesses[i].first.second + dir[chesses[i].second][1], nx = chesses[i].first.first + dir[chesses[i].second][0];
			int cnt = Counting_Move_Chesses(board, i, chesses[i]);
			if (ny <= N && nx <= N && ny >= 1 && nx >= 1) Move(state, board, chesses, cnt, state[ny][nx], i);
			else Move(state, board, chesses, cnt, 2, i);
			if (board[chesses[i].first.second][chesses[i].first.first].size() >= 4) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
		turn++;
	}
	return flag ? turn : -1;
}
void Move(vector<vector<int>>& state_board, vector<vector<vector<int>>>& board, vector<pair<pair<int, int>, int>>& chesses, int move_cnt, int state, int i) {
	switch (state)
	{
		case 0: {
			int y = chesses[i].first.second, x = chesses[i].first.first;
			int ny= y + dir[chesses[i].second][1],nx= x + dir[chesses[i].second][0];
			for (int index = board[y][x].size() - move_cnt; index < board[y][x].size(); index++) {
				board[ny][nx].push_back(board[y][x][index]);
				chesses[board[y][x][index]].first = { nx,ny };
			}
			while (move_cnt--) {
				board[y][x].pop_back();
			}
		}
			  break;
		case 1: {
			int y = chesses[i].first.second, x = chesses[i].first.first;
			int ny = y + dir[chesses[i].second][1], nx = x + dir[chesses[i].second][0];
			int top = board[y][x].size();
			for (int index = 1; index <=move_cnt; index++) {
				int pre = top - index;
				board[ny][nx].push_back(board[y][x][pre]);
				chesses[board[y][x][pre]].first = { nx,ny };
			}
			while (move_cnt--) {
				board[y][x].pop_back();
			}
		};
			break;
		case 2: {
			chesses[i].second = ReversDir(chesses[i].second);
			int y = chesses[i].first.second, x = chesses[i].first.first;
			int ny = y + dir[chesses[i].second][1], nx = x + dir[chesses[i].second][0];
			if (nx >= 1 && nx < state_board.size() && ny >= 1 && ny < state_board.size()) {
				if (state_board[ny][nx] != 2) {
					Move(state_board, board, chesses, move_cnt, state_board[ny][nx], i);
				}
			}
		};
			break;
	}
}

int ReversDir(int pre_dir) {
	if (pre_dir == 1) return 2;
	if (pre_dir == 2) return 1;
	if (pre_dir == 3) return 4;
	if (pre_dir == 4) return 3;
}

int Counting_Move_Chesses(vector<vector<vector<int>>>& board, int chess_num, pair<pair<int, int>, int>& chess_info) {
	int cnt = 1,i;
	int y = chess_info.first.second, x = chess_info.first.first;
	int s = board[y][x].size();
	for (i = 0; i < s; i++) {
		if (board[y][x][i] == chess_num) {
			break;
		}
	}
	return s - i;
}
