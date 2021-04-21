#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int dir[][2] = { {1,0},{0,1},{-1,0}, {0,-1} };//dx, dy
int cycle[2][4] = { {0,3,2,1} ,{0,1,2,3} };	//[0]는 청정기 윗 부분, [1]은 아랫 부분
void spread(vector<vector<int>>& map,int r, int c);	//먼지확산
void clean(vector<vector<int>>& map, vector<pair<int, int>>& cleaner, int r, int c);//청정기 작동
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> cleaner;
	vector<vector<int>> map;
	int R, C, T;
	cin >> R >> C >> T;
	map.resize(R);
	for(int r=0;r<R;r++){
		map[r].resize(C);
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
			if (map[r][c] == -1) {
				cleaner.push_back({ r,c });
			}
		}
	}
	while (T--) {
		spread(map, R,C);
		clean(map, cleaner, R, C);
	}
	int sum = 0;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			sum += map[r][c];
		}
	}
	cout << sum + 2;
	return 0;
}
void spread(vector<vector<int>>& map, int r, int c) {
	queue<pair<pair<int, int>, int>> q;
	for (int row = 0; row < r; row++) {
		for (int col = 0; col < c; col++) {
			if (map[row][col] > 4) {
				q.push({ { row,col },map[row][col] });	//확산될 먼지의 위치를 저장
			}
		}
	}
	while (!q.empty()){//먼지 확산
		pair<pair<int, int>, int> p = q.front(); q.pop();
		int ny, nx,give= p.second /5;
		for (int i = 0; i < 4; i++) {
			ny = p.first.first + dir[i][0];
			nx = p.first.second + dir[i][1];
			if (ny > -1 && ny<r && nx>-1 && nx < c ) {
				if (map[ny][nx] != -1) {
					map[ny][nx] += give;
					map[p.first.first][p.first.second] -= give;
				}
			}
		}
	}
}

void clean(vector<vector<int>>& map, vector<pair<int, int>>& cleaner, int r, int c) {
	int pre_y, pre_x,ny,nx;
	queue<int> q;
	for (int i = 0; i < 2; i++) {
		ny = cleaner[i].first;
		nx = cleaner[i].second+1;
		q.push(map[ny][nx]);
		map[ny][nx] = 0;
		for (int k = 0; k < 4; k++) {
			while (1) {
				pre_y = ny;
				pre_x = nx;
				ny = pre_y + dir[cycle[i][k]][1];
				nx = pre_x + dir[cycle[i][k]][0];
				if (nx >= c || nx < 0 || ny >= r || ny < 0) {
					ny = pre_y;
					nx = pre_x;
					break;
				}
				if (map[ny][nx]==-1) {
					while (!q.empty()) q.pop();
					break;	
				}
				q.push(map[ny][nx]);
				map[ny][nx] = q.front(); q.pop();
			}
		}
	}
}
