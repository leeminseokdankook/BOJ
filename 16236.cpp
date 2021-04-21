#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int dir[][2] = { {1,0},{-1,0},{0,-1},{0,1} };//dx, dy
int find_fish(vector<vector<int>>& place, pair<pair<int, int>, int>& shark);
int solve(vector<vector<int>>& place, pair<pair<int, int>, int>& shark);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<vector<int>> place;
	int N;
	pair<pair<int, int>, int> shark;//{{y,x}, size};
	cin >> N;
	place.resize(N);
	for (int i = 0; i < N; i++) {
		place[i].resize(N);
		for (int j = 0; j < N; j++) {
			cin >> place[i][j];
			if (place[i][j] == 9) {
				shark = { {i,j},2 };
			}
		}
	}
	cout << solve(place, shark);
	return 0;
}

int solve(vector<vector<int>>& place, pair<pair<int, int>, int>& shark) {
	int eat_cnt = 0, time=0;
	while (true) {
		int p = find_fish(place, shark);
		if (!p) return time;
		else {
			time += p;
			eat_cnt++;
			if (eat_cnt == shark.second) {
				shark.second++;
				eat_cnt = 0;
			}
		}
	}
}

int find_fish(vector<vector<int>>& place, pair<pair<int, int>, int>& shark) {
	vector<vector<bool>> visited;
	int N = place.size(), size=shark.second;
	vector<pair<int, int>> fishes;
	visited.resize(N);
	for (int i = 0; i < N; i++) {
		visited[i].resize(N, false);
	}
	queue<pair<pair<int, int>, int>> q;
	visited[shark.first.first][shark.first.second] = true;
	int found = -1;
	q.push({ shark.first,0 });
	while (!q.empty()) {
		pair<pair<int, int>, int> p = q.front(); q.pop();
		if (p.second == found)break;
		for (int i = 0; i < 4; i++) {
			int ny = p.first.first + dir[i][0], nx = p.first.second + dir[i][1];
			if (nx < N && ny < N && nx >= 0 && ny >= 0){
				if (visited[ny][nx]) continue;
				visited[ny][nx] = true;
				if(place[ny][nx] <= size) {
					if (place[ny][nx] && place[ny][nx] < size) {
						found = p.second + 1;
						fishes.push_back({ ny,nx });
					}
					q.push({ {ny,nx},p.second + 1 });
				}
				
			}
		}
	}
	if (found==-1) {
		return 0;
	}
	else {
		sort(fishes.begin(), fishes.end());
		place[shark.first.first][shark.first.second] = 0;
		place[fishes.front().first][fishes.front().second] = 9;
		shark.first = fishes.front();
		return found;
	}
}
