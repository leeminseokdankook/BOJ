#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int* P, n,ans=0;
    bool* is_selected;
    cin >> n;
    P = new int[n];
    is_selected = new bool[n];
    for (int i = 0; i < n; i++) {
        cin >> P[i];
        is_selected[i]=false;
    }
    for (int i = 0; i < n; i++) {
        if (is_selected[i]) continue;
        int index = i;
        ans++;
        do {
            is_selected[index] = true;
            index = P[index];
        } while (!is_selected[index]);
    }
    if (ans == 1) {
        cout << 0;
    }
    else {
        cout << ans;
    }
    delete[] P,is_selected;
    return 0;
}
