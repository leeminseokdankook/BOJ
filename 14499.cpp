#include <iostream>
using namespace std;


enum DIR {
	EAST=1,
	WEST,
	SOUTH,
	NORTH
};

int dir[][2] = { {0,0}, {1,0}, {-1,0}, {0,-1},{0,1} };//dx,dy
bool move_check(int map_row, int map_col, int y, int x);
void next_dice(DIR dir, int* dice);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dice[] = {0,0,0,0,0,0};//z,y,x,-z,-y,-x; y는 남쪽, x는 동쪽 z는 위쪽
	int** map, N, M, K, sy, sx, pre_x, pre_y;
	cin >> N >> M>>sy>>sx>>K;
	map = new int* [N];
	for (int row = 0; row < N; row++) {
		map[row] = new int[M];
		for (int col = 0; col < M; col++) {
			cin >> map[row][col];
		}
	}
	pre_x = sx; pre_y = sy;
	for (int i = 0; i < K; i++) {
		int d;
		cin >> d;
		int ny = pre_y + dir[d][1];
		int nx = pre_x + dir[d][0];
		if (move_check(N, M, ny, nx)) {
			next_dice((DIR)d, dice);
			if (map[ny][nx]) {
				dice[3] = map[ny][nx];
				map[ny][nx] = 0;
			}
			else {
				map[ny][nx] = dice[3];
			}
			pre_y = ny;
			pre_x = nx;
			cout << dice[0] << "\n";
		}
	}
	for (int i = 0; i < N; i++) {
		delete[] map[i];
	}
	delete[] map;
	return 0;
}


bool move_check(int map_row, int map_col, int y, int x) {
	return x > -1 && x < map_col && y<map_row && y>-1;
}

void next_dice(DIR dir, int* dice) {
	//z,y,x,-z,-y,-x, y는 동쪽, x는 남쪽 z는 위쪽
	/*
	EAST=1,
	WEST,
	NORTH,
	SOUTH,
	*/
	int top = dice[0];
	if (dir == 1) {
		/*
		z=-y
		-y=-z
		-z=y
		y=z
		*/
		dice[0] = dice[4];
		dice[4] = dice[3];
		dice[3] = dice[1];
		dice[1] = top;
	}
	else if (dir == 2) {
		/*
		z=y
		y=-z
		-z=y
		y=z
		*/
		dice[0] = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[4];
		dice[4] = top;
	}
	else if (dir == 3) {
		/*
		z=x
		x=-z
		-z=-x
		-x=z
		*/
		dice[0] = dice[2];
		dice[2] = dice[3];
		dice[3] = dice[5];
		dice[5] = top;
	}
	else {
		/*
		z=-x
		-x=-z
		-z=x
		x=z
		*/
		dice[0] = dice[5];
		dice[5] = dice[3];
		dice[3] = dice[2];
		dice[2] = top;
	}
}
