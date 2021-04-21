#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct{
	int red_row, red_col;
	int blue_row, blue_col;
}point;
bool visited[10][10][10][10];	//visited[red_row][red_col][blue_row][blue_col]
int dir[][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };//dy,ds
int solve(vector<string>& board, point& start) {
	queue<point> q;
	point pre;
	visited[start.red_row][start.red_col][start.blue_row][start.blue_col] = true;
	q.push(start);
	bool escape = false;
	int time = 0;
	while (!q.empty()) {
		int count = q.size();
		while (count--) {

			pre = q.front(); q.pop();
			if (board[pre.red_row][pre.red_col] == 'O') {
				escape = true;
				break;
			}
			for (int d = 0; d < 4; d++) {
				int move_cnt[2] = { 0, };
				bool is_out[2] = { false, };
				int pre_point[2][2] = { {pre.red_row, pre.red_col}, {pre.blue_row, pre.blue_col} };
				for (int i = 0; i < 2; i++) {
					while (board[pre_point[i][0] + dir[d][0]][pre_point[i][1] + dir[d][1]] != '#') {
						move_cnt[i]++;
						pre_point[i][0] += dir[d][0]; pre_point[i][1] += dir[d][1];
						if (board[pre_point[i][0]][pre_point[i][1]] == 'O')break;
					}
					is_out[i] = board[pre_point[i][0]][pre_point[i][1]]=='O';
				}
				if (is_out[1]) continue;
				if (pre_point[0][0] == pre_point[1][0] && pre_point[0][1] == pre_point[1][1]) {
					if (move_cnt[0] > move_cnt[1]) {
						pre_point[0][0] -= dir[d][0]; pre_point[0][1] -= dir[d][1];
					}
					else {
						pre_point[1][0] -= dir[d][0]; pre_point[1][1] -= dir[d][1];
					}
				}
				if (visited[pre_point[0][0]][pre_point[0][1]][pre_point[1][0]][pre_point[1][1]]) continue;
				visited[pre_point[0][0]][pre_point[0][1]][pre_point[1][0]][pre_point[1][1]] = true;
				point data = { pre_point[0][0], pre_point[0][1], pre_point[1][0], pre_point[1][1] };
				q.push(data);
			}
		}
		if (escape)break;
		time++;
		if (time > 10) {
			break;
		}
	}
	return escape ? time : -1;
}
int main() {
	vector<string> board;
	int N, M;
	string line;
	point start;
	cin >> N >> M;
	for (int i = 0; i< N; i++) {
		cin >> line;
		for (int j = 0; j < M; j++) {
			if (line[j] == 'B') {
				start.blue_row = i;
				start.blue_col = j;
			}
			else if (line[j] == 'R') {
				start.red_row = i;
				start.red_col = j;
			}
		}
		board.push_back(line);
	}
	printf("%d", solve(board, start));
	return 0;
}
