#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int ans = 0, N,board[20][20];

void shift(int dir);

void DFS(int cnt);

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	DFS(0);
	printf("%d", ans);
	return 0;
}

void DFS(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans = max(ans, board[i][j]);
			}
		}
		return;
	}
	int undo[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			undo[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		shift(i);
		DFS(cnt + 1);
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				board[row][col] = undo[row][col];
			}
		}
	}
}

void shift(int type) {
	/*
	0->move left;
	1->move right;
	2->move up;
	3->move down;
	*/
	queue<int> q;
	switch (type) {
		case 0:
			for (int row = 0; row < N; row++) {
				for (int col = 0; col < N; col++) {
					if (board[row][col]) {
						q.push(board[row][col]);
					}
					board[row][col] = 0;
				}
				int idx = 0;
				while (!q.empty()) {
					int data = q.front(); q.pop();
					if (!board[row][idx]) {
						board[row][idx] = data;
					}
					else if (board[row][idx] == data) {
						board[row][idx] *= 2;
						idx++;
					}
					else {
						idx++;
						board[row][idx] = data;
					}
				}
			}
			break;
		case 1:
			for (int row = 0; row < N; row++) {
				for (int col = N - 1; col > -1; col--) {
					if (board[row][col]) {
						q.push(board[row][col]);
					}
					board[row][col] = 0;
				}
				int idx = N - 1;
				while (!q.empty()) {
					int data = q.front(); q.pop();
					if (!board[row][idx]) {
						board[row][idx] = data;
					}
					else if (board[row][idx] == data) {
						board[row][idx] *= 2;
						idx--;
					}
					else {
						idx--;
						board[row][idx] = data;
					}
				}
			}
			break;
		case 2:
			for (int col = 0; col < N; col++) {
				for (int row = 0; row < N; row++) {
					if (board[row][col]) {
						q.push(board[row][col]);
					}
					board[row][col] = 0;
				}
				int idx = 0;
				while (!q.empty()) {
					int data = q.front(); q.pop();
					if (!board[idx][col]) {
						board[idx][col] = data;
					}
					else if (board[idx][col] == data) {
						board[idx][col] *= 2;
						idx++;
					}
					else {
						idx++;
						board[idx][col] = data;
					}
				}
			}
			break;
		case 3:
			for (int col = 0; col < N; col++) {
				for (int row = N - 1; row > -1; row--) {
					if (board[row][col]) {
						q.push(board[row][col]);
					}
					board[row][col] = 0;
				}
				int idx = N - 1;
				while (!q.empty()) {
					int data = q.front(); q.pop();
					if (!board[idx][col]) {
						board[idx][col] = data;
					}
					else if (board[idx][col] == data) {
						board[idx][col] *= 2;
						idx--;
					}
					else {
						idx--;
						board[idx][col] = data;
					}
				}
			}
			break;
	}
}
