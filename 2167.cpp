#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, dp[301][301] = { 0 },K;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int val;
            cin >> val;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + val;
        }
    }
    cin >> K;
    while (K--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << dp[x][y] - dp[i - 1][y] - dp[x][j - 1] + dp[i - 1][j - 1] << '\n';
    }
    return 0;
}
