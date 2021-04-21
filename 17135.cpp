#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int dir[4][2] = { 1,0,0,-1,-1,0 };
bool Is_End(vector<vector<int>>& board);   //게임이 종료되면 true, 아니면 false 반환
int Solve(vector<vector<int>>& board, int D);//전체 풀이
int Select(vector<vector<int>>& board, int D, int index, int cnt, vector<int>& position);//궁수 위치 선택
int Shot(vector<vector<int>>& board, vector<int>& position, int D);//활을 쏨
void Move_enermy(vector<vector<int>>& board);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, D;
    vector<vector<int>> board;
    cin >> N >> M >> D;
    board.resize(N, vector<int>(M));//N*M 격자판
    for (vector<int>& v : board) {//입력
        for (int& x : v) {
            cin >> x;
        }
    }
    cout << Solve(board, D);
    return 0;
}
int Solve(vector<vector<int>>& board, int D) {
    vector<int> position;
    return Select(board, D, -1, 0, position);
}

int Select(vector<vector<int>>& board, int D, int index, int cnt, vector<int>& position) {
    int ret = 0;
    if (cnt == 3) {
        vector<vector<int>> cpy = board;
        while (!Is_End(cpy)) {
            ret += Shot(cpy, position, D);
            Move_enermy(cpy);
        }
        return ret;
    }
    int M = board[0].size();
    for (int i = index + 1; i < M; i++) {
        position.push_back(i);
        ret = max(ret, Select(board, D, i, cnt + 1, position));
        position.pop_back();
    }
    return ret;
}

bool Is_End(vector<vector<int>>& board) {
    for (vector<int>& v : board) {
        for (int& x : v) {
            if (x) {
                return false;
            }
        }
    }
    return true;
}

int Shot(vector<vector<int>>& board, vector<int>& position, int D) {
    int N = board.size(), M=board[0].size();
    int kill_cnt = 0;
    pair<int, int>* killed_enermy_position = new pair<int, int>[position.size()];
    for (int index = 0; index < position.size();index++) {
        queue<pair<pair<int, int>, int>> q;//position , dis
        pair<int, int> temp = { INT32_MAX, INT32_MAX };
        vector<vector<bool>> visited;
        int init_x = position[index], init_y = N,min_dis=D;
        visited.resize(N, vector<bool>(N, false));
        q.push({ {init_x, init_y }, 0 });
        while (!q.empty()) {
            int x = q.front().first.first, y = q.front().first.second, dis = q.front().second;
            q.pop();
            if (dis == min_dis) {
                break;
            }
            for (int i = 0; i < 3; i++) {
                int ny = y + dir[i][1], nx = x + dir[i][0];
                if (ny<N && ny>-1 && nx<M && nx>-1) {
                    if (!visited[ny][nx]) {
                        visited[ny][nx] = true;
                        if (dis + 1 <= min_dis) {
                            q.push({ {nx,ny}, dis + 1 });
                            if (board[ny][nx]) {
                                min_dis = dis + 1;
                                if (temp.first > nx) {
                                    temp = { nx,ny };
                                }
                            }
                        }
                    }
                }
            }
        }
        killed_enermy_position[index] = temp;
    }
    for (int index = 0; index < position.size(); index++) {
        int y = killed_enermy_position[index].second, x = killed_enermy_position[index].first;
        if (y == INT32_MAX && x == INT32_MAX)continue;
        if (board[y][x]) {
            board[y][x] = 0;
            kill_cnt++;
        }
    }
    delete[] killed_enermy_position;
    return kill_cnt;
}

void Move_enermy(vector<vector<int>>& board) {
    int N = board.size(), M = board[0].size();
    for (int row = N - 1; row > 0; row--) {
        for (int col = 0; col < M; col++) {
            board[row][col] = board[row - 1][col];
        }
    }
    for (int col = 0; col < M; col++) {
        board[0][col] = 0;
    }
}

