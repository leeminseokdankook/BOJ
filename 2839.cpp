#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, cnt_3=0;
    cin >> N;
    while (N>=0) {
        if (N % 5) {
            cnt_3++;
        }
        else {
            cout << cnt_3 + N / 5;
            return 0;
        }
        N -= 3;
    }
    cout << -1;
    return 0;
}
