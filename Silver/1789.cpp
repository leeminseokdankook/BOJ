#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    unsigned long long int S, sum=0LL, ans;
    cin >> S;
    for (ans= 1LL;1 ;ans++) {
        sum += ans;
        if (S < sum) {
            ans--;
            break;
        }
    }
    cout << ans;
    return 0;
}



