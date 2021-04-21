#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10
#define MAX_PAPER 5
#define INTMAX ~(1 << (sizeof(int) * 8 - 1))
using namespace std;

int ans=INTMAX;

void DFS(vector<vector<int>>& table, vector<int>& paper_cnt, int sy, int sx,int cnt);
bool Can_Attach(vector<vector<int>>& table, int y, int x, int size);
void Attach(vector<vector<int>>& table, int y, int x, int size);
void DisAttach(vector<vector<int>>& table, int y, int x, int size);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> table;
    vector<int> paper_cnt(MAX_PAPER+1, 5);
    table.resize(MAX, vector<int>(MAX));
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> table[i][j];
        }
    }
    DFS(table, paper_cnt, 0, 0, 0);
    if (ans == INTMAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }
    return 0;
}

void DFS(vector<vector<int>>& table, vector<int>& paper_cnt, int sy, int sx, int cnt) {
    int x = sx,  y = sy;
    do {
        while (x < MAX) {
            if (table[y][x]) {
                break;
            }
            x++;
        }
        if (x < MAX) {
            break;
        }
        y++;
        x = 0;
    } while (y < MAX);
    if (y == MAX) {
        ans = min(ans, cnt);
    }
    else if (ans < cnt) {
        return;
    }
    for (int size = MAX_PAPER; size > 0; size--) {
        if (x + size > MAX || y + size > MAX || paper_cnt[size] == 0)continue;
        if (Can_Attach(table, y, x, size)) {
            Attach(table, y, x, size);
            paper_cnt[size]--;
            DFS(table, paper_cnt, sy, sx + size, cnt + 1);
            DisAttach(table, y, x, size);
            paper_cnt[size]++;
        }
    }
}

bool Can_Attach(vector<vector<int>>& table, int y, int x, int size) {
    int end_row = y + size, end_col = x + size;
    for (int sy = y; sy < end_row; sy++) {
        for (int sx = x; sx < end_col; sx++) {
            if (table[sy][sx] == 0) {
                return false;
            }
        }
    }
    return true;
}

void Attach(vector<vector<int>>& table, int y, int x, int size) {
    int end_row = y + size, end_col = x + size;
    for (int sy = y; sy < end_row; sy++) {
        for (int sx = x; sx < end_col; sx++) {
            table[sy][sx] = 0;
        }
    }
}

void DisAttach(vector<vector<int>>& table, int y, int x, int size) {
    int end_row = y + size, end_col = x + size;
    for (int sy = y; sy < end_row; sy++) {
        for (int sx = x; sx < end_col; sx++) {
            table[sy][sx] = 1;
        }
    }
}
