#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> board;
	const int SNAKE = 1;
	const int APPLE = 2;
	queue<pair<int, char>> dir_queue;
	int dir_index = 0, N,K,L;
	queue<pair<int, int>> snake;
	pair<int, int> head = { 1,1 };
	/*
	왼쪽으로 회전 -> (dir_index+3)%4
	오른 쪽으로 회전 -> (dir_index+1)%4
	*/
	int dir[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };	//dx, dy
	int sec = 0;
	cin >> N;
	board.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		board[i].resize(N + 1, 0);
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int row, col;
		scanf("%d %d", &row, &col);
		board[row][col] = APPLE;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int s;
		char d;
		scanf("%d %c", &s, &d);
		dir_queue.push(make_pair(s, d));
	}
	snake.push(head);
	board[1][1] = SNAKE;
	while (1) {
		sec++;
		int ny = head.first + dir[dir_index][1];
		int nx = head.second + dir[dir_index][0];
		if (ny < 1 || nx<1 || ny>N || nx > N) {
			break;
		}
		else if (board[ny][nx] == SNAKE) {
			break;
		}
		else if (board[ny][nx] != APPLE) {
			pair<int, int> tail = snake.front();
			snake.pop();
			board[tail.first][tail.second] = 0;
		}
		head = { ny,nx };
		snake.push(head);
		board[ny][nx] = SNAKE;
		if (!dir_queue.empty() && sec == dir_queue.front().first) {
			if (dir_queue.front().second == 'L') {
				dir_index = (dir_index + 3) % 4;
			}
			else {
				dir_index = (dir_index + 1) % 4;
			}
			dir_queue.pop();
		}
	}
	printf("%d", sec);
	return 0;
}
