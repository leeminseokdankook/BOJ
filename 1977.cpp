#include <iostream>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int M, N, sum=0, mini=1;
    cin >> M >> N;
    while (mini * mini < M) {
        mini++;
    }
    if (mini * mini > N) {
        cout << -1;
        return 0;
    }
    for (int n = mini; n * n <= N; n++) {
        sum += (n * n);
    }
    cout << sum << '\n'<<mini*mini;
    return 0;
}


