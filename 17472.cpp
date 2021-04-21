#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;
/*
1. 섬마다 번호 매기기 (BFS)
2. 다리 연결	(DFS)
3. Prim알고리즘 적용
*/

int dir[][2] = {
	1,0,
	0,1,
	-1,0,
	0,-1
};
void MakeBridge(int x, int y, int d, vector<vector<int>>& map, vector<vector<int>>& weight, int start, int len);
void MakeLabel(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& visited, int label);
int PrimAlgorithm(vector<vector<int>>& weight);
int Solve(vector<vector<int>>& map);

int main() {
	int N, M;
	vector<vector<int>> map;
	ios::sync_with_stdio(false);
	cin >> N >> M;
	map.resize(N, vector<int>(M));
	for (vector<int>& v : map) {
		for (int& val : v) {
			cin >> val;
		}
	}
	cout << Solve(map);
	return 0;
}

int Solve(vector<vector<int>>& map) {
	int N=map.size(), M=map[0].size();
	vector<vector<bool>> graph;
	vector<vector<bool>> visited;
	vector<vector<int>> weight;
	visited.resize(map.size(), vector<bool>(map[0].size(), false));
	//라벨링
	int label = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				MakeLabel(j, i, map, visited, label++);
			}
			visited[i][j] = true;
		}
	}
	weight.resize(label, vector<int>(label, INT32_MAX));
	//다리 연결
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x]) {
				for (int i = 0; i < 4; i++) {
					MakeBridge(x, y, i, map, weight, map[y][x], 0);
				}
			}
		}
	}
	//Prim적용
	return PrimAlgorithm(weight);
}


void MakeBridge(int x, int y, int d, vector<vector<int>>& map, vector<vector<int>>& weight, int start, int len) {
	int ny = y + dir[d][0], nx = x + dir[d][1];
	if (ny < 0 || ny >= map.size() || nx < 0 || nx >= map[0].size()) return;
	if (map[ny][nx] == start)return;
	if (map[ny][nx] == 0) MakeBridge(nx, ny, d, map, weight, start, len + 1);
	else {
		if (len > 1) {
			weight[start][map[ny][nx]] = weight[map[ny][nx]][start] = min(weight[start][map[ny][nx]], len);
		}
	}
}

void MakeLabel(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& visited, int label) {
	int N = map.size(), M = map[0].size();
	queue<pair<int, int>> q;
	visited[y][x] = true;
	map[y][x] = label;
	q.push({ x,y });
	while (!q.empty()) {
		int p_x = q.front().first;
		int p_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = p_y + dir[i][0], nx = p_x + dir[i][1];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx]) {
				map[ny][nx] = label;
				visited[ny][nx] = true;
				q.push({ nx,ny });
			}
		}
	}
}

int PrimAlgorithm(vector<vector<int>>& weight) {
	int ret=INT32_MAX;
	int picked=0;		//연결된 정점(비트마스크)
	int island_cnt = weight.size() - 1;
	int allpick = 0;
	for (int i = 1; i <= island_cnt; i++) {
		allpick |= 1 << i;
	}
	for (int i = 1; i <= island_cnt; i++) {
		int sum = 0;
		picked |= 1 << i;
		while(1)
		{
			int min_weight = INT32_MAX;
			int pick_point = 0;
			for (int n = 1; n <= island_cnt; n++) {		//선택된 정점을 고름
				if (picked & 1 << n) {						//정점을 선택
					for (int p = 1; p <= island_cnt; p++) {	//고른 정점과 연결된 정점들을 순회
						if (weight[n][p] == INT32_MAX) continue;	//끊겨 있으면 넘어감
						if (picked & 1 << p) continue;				//이미 뽑힌 정점이면 넘김 (싸이클방지)
						if (weight[n][p] < min_weight) {
							min_weight = weight[n][p];
							pick_point = p;
						}
					}
				}
			}
			if (pick_point) {
				picked |= 1 << pick_point;
				sum += min_weight;
			}
			else {
				break;
			}
		}
		if (picked == allpick) {
			ret = min(ret, sum);
		}
		picked = 0;
	}
	return ret == INT32_MAX ? -1 : ret;
}
