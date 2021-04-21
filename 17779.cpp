#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int Solve(vector<vector<int>>& place);
int Select(vector<vector<int>>& place, int x, int y, int d1, int d2);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<vector<int>> place;
	int N;
	cin >> N;
	place.resize(N+1);
	for (int i = 1; i <= N; i++) {
		place[i].resize(N+1);
		for (int j = 1; j <= N; j++) {
			cin >> place[i][j];
		}
	}
	cout << Solve(place);
	return 0;
}

int Solve(vector<vector<int>>& place){
	int ans = INT32_MAX;
	int N = place.size()-1;
	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			int d1 = 1, d2 = 1;
			while (true) {
				if (x + d1 + d2 <= N && 1 <= y - d1 && y + d2 <= N) {
					ans = min(ans, Select(place, x, y, d1, d2++));
				}
				else {
					d1++; d2 = 1;
					if (!(x + d1 + d2 <= N && 1 <= y - d1 && y + d2 <= N)) {
						break;
					}
				}
			}
		}
	}
	return ans;
}

int Select(vector<vector<int>>& place, int x, int y, int d1, int d2) {		
	vector<int> people;
	vector<vector<bool>> visited;
	int n=place.size(),i,j;
	people.resize(5,0);
	visited.resize(n);
	for (vector<bool>& v : visited) {
		v.resize(n, false);
	}
	//5번 경계선
	for (i = 0; i <= d1; i++) {
		visited[x + i][y - i] = true;
		visited[x + d2 + i][y - i + d2] = true;
		people[4] += place[x + i][y - i] + place[x + d2 + i][y - i + d2];
	}
	for (i = 1; i < d2; i++) {
		visited[x + i][y + i] = true;
		visited[x + d1 + i][y - d1 + i] = true;
		people[4] += place[x + i][y + i] + place[x + d1 + i][y - d1 +i];
	}
	//내부
	for (i = 0; i < d1; i++) {
		for (j = 1; !visited[x + i + j][y - i]; j++) {
			visited[x + i + j][y - i] = true;
			people[4] += place[x + i + j][y - i];
		}
	}
	for (i = 1; i < d2; i++) {
		for (j = 1; !visited[x + i + j][y + i]; j++) {
			visited[x + i + j][y + i] = true;
			people[4] += place[x + i + j][y + i];
		}
	}
	for (i = 1; i < n; i++) {
		for (j = 1; j < n; j++) {
			if (!visited[i][j]) {
				if (i < x + d1 && j <= y)people[0] += place[i][j];
				else if (i <= x + d2 && j > y)people[1] += place[i][j];
				else if (i >= x + d1 && j < y - d1 + d2)people[2] += place[i][j];
				else if (i > x + d2 && j >= y - d1 + d2) people[3] += place[i][j];
			}
		}
	}
	int large = INT32_MIN, small=INT32_MAX;
	for (int x : people) {
		if (large < x) {
			large = x;
		}
		if (small > x) {
			small = x;
		}
	}

	return large - small;
}
