#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int dist_calcu(pair<int, int>& house, pair<int, int>& chick);
int DFS(vector<pair<int, int>>& house,vector<pair<int, int>>& chick, vector<bool>& visited, int index, int cnt, int m);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> chick, house;
	vector<bool> visited;
	pair<int, int> p;
	int n, m;
	cin >> n >> m;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			int is_chick;
			cin >> is_chick;
			if (is_chick == 2) {
				chick.push_back({ row,col });
				visited.push_back(false);
			}
			else if(is_chick==1){
				house.push_back({ row, col });
			}
		}
	}
	int ans = DFS(house, chick, visited, 0,0,m);
	cout << ans;
	return 0;
}
int DFS(vector<pair<int, int>>& house, vector<pair<int, int>>& chick, vector<bool>& visited, int index, int cnt, int m) {
	if (cnt == m) {
		int total=0;
		for (pair<int, int>& h : house) {
			int dis = INT32_MAX;
			for (int i = 0; i < chick.size(); i++) {
				if (visited[i]) {
					dis = min(dis, dist_calcu(h, chick[i]));
				}
			}
			total += dis;
		}
		return total;
	}
	else if (index == visited.size()) {
		return INT32_MAX;
	}
	else {
		int ret = INT32_MAX;
		visited[index] = true;
		ret = min(ret, DFS(house, chick, visited, index + 1, cnt + 1, m));
		visited[index] = false;
		ret = min(ret, DFS(house, chick, visited, index + 1, cnt, m));
		return ret;
	}
}

int dist_calcu(pair<int, int>& house, pair<int, int>& chick) {
	return abs(house.first - chick.first) + abs(house.second - chick.second);
}
