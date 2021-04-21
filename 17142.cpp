#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int Select(vector<vector<int>>& lab, vector<pair<int, int>>& position, vector<pair<int, int>>& selected, int index, int M);
int BFS(vector<vector<int>>& lab, vector<pair<int, int>>& selected);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    vector<vector<int>> lab;
    vector<pair<int, int>> position;
    vector<pair<int, int>> selected;
    cin >> N >> M;
    lab.resize(N);
    for (int i = 0; i < N; i++) {
        lab[i].resize(N);
        for (int j = 0; j < N; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 2) {
                position.push_back({ i,j });
            }
        }
    }
    int ans = Select(lab, position, selected, -1, M);
    if (ans == INT32_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }
    return 0;
}

int Select(vector<vector<int>>& lab, vector<pair<int, int>>& position, vector<pair<int, int>>& selected, int index, int M) {
    if (selected.size() == M) {
        return BFS(lab, selected);
    }
    if (position.size() - (index+1) < M - selected.size()) {
        return INT32_MAX;
    }
    int ret = INT32_MAX;
    for (int n = index + 1; n < position.size(); n++) {
        selected.push_back(position[n]);
        ret = min(ret, Select(lab, position, selected, n, M));
        selected.pop_back();
    }
    return ret;
}
int BFS(vector<vector<int>>& lab, vector<pair<int, int>>& selected) {
    queue<pair<int, int>> q;
    queue<pair<int, int>> track;
    vector<vector<bool>> visited;

    int n = lab.size();
    int time=0, temp=0;
    visited.resize(n);
    for (int i = 0; i < n; i++) {
        visited[i].resize(n, false);
    }
    for (vector<pair<int, int>>::iterator iter = selected.begin(); iter != selected.end(); iter++) {
        visited[iter->first][iter->second] = true;
        q.push(*iter);
    }
    while (!q.empty()) {
        bool is_spread = false;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            pair<int, int>p = q.front(); q.pop();
            track.push(p);
            int ny, nx;
            for (int k = 0; k < 4; k++) {
                ny = p.first + dir[k][1];
                nx = p.second + dir[k][0];
                if (ny > -1 && ny<n && nx>-1 && nx < n) {
                    if (!visited[ny][nx]) {
                        visited[ny][nx] = true;
                        if (lab[ny][nx] == 0) {
                            q.push({ ny, nx });
                            is_spread = true;
                        }
                        else if(lab[ny][nx]==2){
                            q.push({ ny, nx });
                        }
                    }
                }
            }
        }
        if (!is_spread) {
            temp++;
        }
        else {
            temp++;
            time += temp;
            temp = 0;
        }
    }
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (lab[row][col] == 0) {
                if (!visited[row][col]) {
                    return INT32_MAX;
                }
            }
        }
    }
    return time;
}
