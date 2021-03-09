#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, *heights, left_cnt=1, right_cnt=1, max_height;
    cin >> N;
    heights = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    //왼쪽에서 본 것
    max_height = heights[0];
    for (int i = 1; i < N; i++) {
        if (max_height < heights[i]) {
            left_cnt++;
            max_height = heights[i];
        }
    }
    max_height = heights[N - 1];
    for (int i = N - 2; i > -1; i--) {
        if (max_height < heights[i]) {
            right_cnt++;
            max_height = heights[i];
        }
    }
    cout << left_cnt << '\n' << right_cnt;
    return 0;
}



