#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10
#define MAX_PAPER 5
#define INTMIN (1 << (sizeof(int) * 8 - 1))
using namespace std;

int ans = INTMIN;

int Playing(vector<int>& player_result, vector<int>& order, int& start_index);
void Select(vector<vector<int>>& player_result, vector<bool>& is_selected, vector<int>& player_order, int pre);
void Solve(vector<vector<int>>& player_result);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    vector<vector<int>> player_result;
    cin >> N;
    player_result.resize(N, vector<int>(9));
    for (vector<int>& v : player_result){
        for (int i = 0; i < 9; i++) {
            cin >> v[i];
        }
    }
    Solve(player_result);
    cout << ans;
    return 0;
}

void Solve(vector<vector<int>>& player_result) {
    vector<bool> is_selected(9, false);
    vector<int> player_order(9, 0);
    is_selected[3] = true;
    player_order[3] = 0;
    Select(player_result, is_selected, player_order,1);
}

void Select(vector<vector<int>>& player_result, vector<bool>& is_selected, vector<int>& player_order, int pre) {
    if (pre == 9) {
        int score = 0, start_index = 0;
        for (vector<int>& v : player_result) {
            score += Playing(v, player_order, start_index);
        }
        ans = max(ans, score);
    }
    else{
        for (int order = 0; order < 9; order++) {
            if (is_selected[order])continue;
            player_order[order] = pre;
            is_selected[order] = true;
            Select(player_result, is_selected, player_order, pre + 1);
            is_selected[order] = false;
        }
    }
}

int Playing(vector<int>& player_result, vector<int>& order, int& start) {
    int score=0;
    queue<int> base;
    for (int i = 0; i < 3; i++) {
        base.push(0);
    }
    int out_cnt = 0;
    while (out_cnt != 3) {
        int Batter = order[start];
        int run = player_result[Batter];
        switch (run)
        {
            case 0:
                out_cnt++;
                break;
            default:
                base.push(1);
                for (int i = 0; i < run; i++) {
                    if (base.front()) {
                        score++;
                    }
                    base.pop();
                }
                run--;
                for (int i = 0; i < run; i++) {
                    base.push(0);
                }
                break;
        }
        start = (start + 1) % 9;
    }
    return score;
}
