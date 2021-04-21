#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;

pair<pair<int, int>, int> pick_up(vector<vector<int>>& map, pair<pair<int, int>, int>& car);
int Solve(vector<vector<int>>& map, vector<pair<int, int>>& end_position, pair<pair<int, int>, int> car);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<int>> map;
	pair<pair<int, int>, int> car;	//지점, 남은 연료
	vector<pair<int, int>> end_position;
	int N, M, fuel, sy, sx;
	cin >> N >> M >> fuel;
	map.resize(N + 1, vector<int>(N + 1));
	end_position.resize(M+1);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> sy >> sx;
	car = { {sx,sy}, fuel };
	for (int i = 1; i <= M; i++) {
		int p_x, p_y,e_x,e_y;	//대기 장소, 목적지
		cin >> p_y >> p_x >> e_y >> e_x;
		map[p_y][p_x] = i * -1;	//대기 장소에 사람 번호 * -1 로 구분
		end_position[i] = { e_x, e_y };
	}
	cout << Solve(map, end_position, car);
	return 0;
}

int Solve(vector<vector<int>>& map, vector<pair<int, int>>& end_position, pair<pair<int, int>, int> car) {
	int people_cnt = end_position.size() - 1;
	int dir[][2] = { 1,0,0,1,-1,0,0,-1 };
	int N = map.size() - 1;
	while (people_cnt) {
		pair<pair<int, int>, int> p = pick_up(map, car);			//픽업할 사람을 고름
		if (p.second == -1) {
			return -1;
		}
		int end_x = end_position[p.second].first, end_y = end_position[p.second].second;	//최종 목적지
		queue<pair<pair<int, int>, int>> q;		//지점과 거리
		map[p.first.second][p.first.first] = 0;
		//
		//BFS로 최종 목적지 까지 탐색
		//
		vector<vector<bool>> visited;
		visited.resize(map.size(), vector<bool>(map.size(), false));
		q.push({ { car.first.first, car.first.second }, 0 });
		visited[car.first.second][car.first.first] = true;
		int use_fuel = -1;
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int fuel = q.front().second;
			q.pop();
			if (x == end_x && y == end_y) {
				use_fuel = fuel;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int ny = y + dir[i][1], nx = x + dir[i][0];
				if (ny <= 0 || ny > N || nx <= 0 || nx > N)continue;
				if (visited[ny][nx])continue;
				visited[ny][nx] = true;
				if (map[ny][nx] == 1)continue;
				q.push({ {nx,ny},fuel + 1 });
			}
		}
		if (use_fuel == -1|| use_fuel > car.second) {
			//사용할 연료가 차에 남은 연료보다 많거나 목적지에 갈 수 없을 때 
			return -1;
		}
		car.first.first = end_x;
		car.first.second = end_y;
		car.second += use_fuel;		//사용한 연료만큼 추가
		people_cnt--;				//승객하차
	}
	return car.second;
}

pair<pair<int, int>, int> pick_up(vector<vector<int>>& map, pair<pair<int, int>, int>& car) {
	vector<vector<bool>> visited;
	int N = map.size() - 1;
	int min_distance=INT32_MAX;					//픽업 거리
	list<pair<int, int>> pickup_list;			//픽업할 사람 목록
	int dir[][2] = { 1,0,0,1,-1,0,0,-1 };
	queue < pair<pair<int, int>, int>> q;
	visited.resize(map.size(), vector<bool>(map.size(), false));
	q.push({ { car.first.first, car.first.second }, 0 });
	visited[car.first.second][car.first.first] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int fuel = q.front().second;
		q.pop();
		if (map[y][x]<0&&fuel<=min_distance) {
			min_distance = fuel;
			pickup_list.push_back({ y,x });
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][1], nx = x + dir[i][0];
			if (ny <= 0 || ny > N || nx <= 0 || nx > N)continue;
			if (visited[ny][nx])continue;
			visited[ny][nx] = true;
			if (map[ny][nx] == 1)continue;
			q.push({ {nx,ny},fuel + 1 });
		}
	}
	if (pickup_list.size() == 0) {
		return { {0,0},-1 };
	}
	else {
		pickup_list.sort(less<>());
		car.second -= min_distance;
		int y = pickup_list.front().first, x = pickup_list.front().second;
		car.first.first = x; car.first.second = y;
		return { {x,y}, map[y][x] * -1 };
	}
}



