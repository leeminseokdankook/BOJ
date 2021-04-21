

#include <iostream>
#include <vector>
using namespace std;

//동쪽 == 0
//대각선 == 1
//아래 == 2
int dir[3][2] = { {1,0}, {1,1}, {0,1} };
int Connect(vector<vector<int>>& board, int sx, int sy, int n, int pipe) {
    if (sy == n && sx == n) {
        return 1;
    }
    int ret = 0;
    for (int i = 0; i < 3; i++) {
        if ((i == 0 && pipe == 2) || (i == 2 && pipe == 0)) {
            continue;
        }
        int ny = sy + dir[i][1], nx = sx + dir[i][0];
        if (ny > n || nx > n || board[ny][nx]) {
            continue;
        }
        if (i == 1 && (board[sy + 1][sx] || board[sy][sx + 1])) {
            continue;
        }
        ret += Connect(board, nx, ny, n, i);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> board;
    int n;
    cin >> n;
    board.resize(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    cout << Connect(board, 2, 1, n, 0);
    return 0;
}
