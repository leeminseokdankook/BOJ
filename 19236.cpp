#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int ans = INT32_MIN;
int dir[][2] = {0,-1,-1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1};//dx,dy
bool is_killed[17] = { false, };

void fishes_Move(vector<vector<int>>& fishes_num, vector<pair<pair<int, int>, int>>& fishes_info, int shark_x, int shark_y);
bool is_end(vector<vector<int>>& fishes_num, int shark_x, int shark_y, int shark_dir);
void next(vector<vector<int>> fishes_num, vector<pair<pair<int, int>, int>> fishes_info, int shark_x, int shark_y, int shark_dir, int pre_score, list<int>&eat_list);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<int>> fishes_num(4,vector<int>(4));
	vector<pair<pair<int, int>, int>> fishes_info(17);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int x;
			cin >> x;//fishes_num[i][j];
			cin >> fishes_info[x].second;
			fishes_info[x].second -= 1;
			fishes_info[x].first= { i,j };
			fishes_num[i][j] = x;
		}
	}
	int first_fish = fishes_num[0][0];
	int first_dir = fishes_info[first_fish].second;
	fishes_num[0][0] = 0;
	is_killed[first_fish] = true;
	list<int> eat_list;
	eat_list.push_back(first_fish);
	next(fishes_num, fishes_info, 0, 0, first_dir, first_fish,eat_list);
	cout << ans;
	return 0;
}

void next(vector<vector<int>> fishes_num, vector<pair<pair<int, int>, int>> fishes_info, int shark_x, int shark_y, int shark_dir, int pre_score, list<int>&eat_list) {
	vector<pair<pair<int, int>, int>> info_cpy = fishes_info;
	fishes_Move(fishes_num, fishes_info, shark_x, shark_y);
	if (is_end(fishes_num, shark_x, shark_y, shark_dir)) {
		ans = max(ans, pre_score);
		fishes_info = info_cpy;
		return;
	}
	int dx = dir[shark_dir][0], dy= dir[shark_dir][1];
	for (int next_y = dy + shark_y, next_x = dx + shark_x; next_y < 4 && next_y >= 0 && next_x >= 0 && next_x < 4; next_y += dy, next_x += dx) {
		if (fishes_num[next_y][next_x]) {
			int score = fishes_num[next_y][next_x];
			fishes_num[next_y][next_x] = 0;
			int d = fishes_info[score].second;
			eat_list.push_back(score);
			is_killed[score] = true;
			next(fishes_num, fishes_info, next_x, next_y, d, pre_score + score, eat_list);
			is_killed[score] = false;
			fishes_num[next_y][next_x] = score;
			eat_list.pop_back();
		}
	}
}

void fishes_Move(vector<vector<int>>& fishes_num, vector<pair<pair<int, int>, int>>& fishes_info, int shark_x, int shark_y) {
	for (int i = 1; i <= 16; i++) {
		if (is_killed[i])continue;
		int d = fishes_info[i].second;
		int x = fishes_info[i].first.second, y = fishes_info[i].first.first;
		int dx = dir[d][0], dy = dir[d][1];
		int next_y = y + dy, next_x = x + dx;
		while (next_y >= 4 || next_y < 0 || next_x >= 4 || next_x < 0 || (shark_x == next_x && shark_y == next_y)) {
			d = (d + 1) % 8;
			next_y = y + dir[d][1];
			next_x = x + dir[d][0];
		}
		if (!fishes_num[next_y][next_x]) {
			fishes_info[i] = { {next_y, next_x}, d };
			
		}
		else {
			fishes_info[i].second = d;
			int change_fish = fishes_num[next_y][next_x];
			pair<int, int> temp = fishes_info[i].first;
			fishes_info[i].first = fishes_info[change_fish].first;
			fishes_info[change_fish].first = temp;
		}
		swap(fishes_num[y][x], fishes_num[next_y][next_x]);
	}
}

bool is_end(vector<vector<int>>& fishes_num, int shark_x, int shark_y, int shark_dir) {
	int dy = dir[shark_dir][1], dx = dir[shark_dir][0];
	for (int next_y = shark_y + dy, next_x = shark_x + dx; next_y < 4 && next_y >= 0 && next_x < 4 && next_x >= 0; next_y += dy, next_x += dx) {
		if (fishes_num[next_y][next_x]) {
			return false;
		}
	}
	return true;
}
