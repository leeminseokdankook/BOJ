#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, * lengthes;
    cin >> N;
    lengthes = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> lengthes[i];
    }
    //오름차순 정렬
    sort(lengthes, lengthes + N);
    N--;
    while (N > 1) {
        if (lengthes[N] < lengthes[N - 1] + lengthes[N - 2]) {
            cout << lengthes[N] + lengthes[N - 1] + lengthes[N - 2];
            return 0;
        }
        N--;
    }
    cout << -1;
    return 0;
}



