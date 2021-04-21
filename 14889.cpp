#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int score(vector<vector<int>>& state, vector<int>& pick, vector<int>& not_pick);
int DFS(vector<vector<int>>& stat, int n, vector<int>& pick, vector<bool>& is_pick,int v);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<vector<int>> state;
	vector<bool> is_pick;
	vector<int> pick;
	int N;
	cin >> N;
	state.resize(N);
	is_pick.resize(N, false);
	for (int row = 0; row < N; row++) {
		state[row].resize(N);
		for (int col = 0; col < N; col++) {
			cin >> state[row][col];
		}
	}
	is_pick[0] = true;
	pick.push_back(0);
	cout << DFS(state, 1, pick, is_pick, 0);
	return 0;
}

int DFS(vector<vector<int>>& state, int n, vector<int>& pick, vector<bool>& is_pick, int v) {
	if (state.size() / 2 == n) {
		int index = 0;
		vector<int> another;
		for (int i = 0; i < state.size(); i++) {
			if (!is_pick[i]) {
				another.push_back(i);
			}
		}
		return score(state, pick, another);
	}
	int ans = INT32_MAX;
	for (int i = v + 1; i < state.size(); i++) {
		pick.push_back(i);
		is_pick[i] = true;
		ans = min(ans, DFS(state, n + 1, pick, is_pick,i));
		is_pick[i] = false;
		pick.pop_back();
	}
	return ans;
}



int score(vector<vector<int>>& state, vector<int>& pick, vector<int>& not_pick) {
	int pick_score, not_pick_score;
	pick_score = not_pick_score = 0;
	for (int i = 0; i < pick.size() - 1; i++) {
		for (int j = i + 1; j < pick.size(); j++) {
			pick_score += (state[pick[i]][pick[j]] + state[pick[j]][pick[i]]);
		}
	}
	for (int i = 0; i < pick.size() - 1; i++) {
		for (int j = i + 1; j < pick.size(); j++) {
			not_pick_score += (state[not_pick[i]][not_pick[j]] + state[not_pick[j]][not_pick[i]]);
		}
	}
	return abs(pick_score - not_pick_score);
}
