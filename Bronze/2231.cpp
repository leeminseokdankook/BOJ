#include <iostream>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num, cnt = 0;
    cin >> num;
    for (int i = 1; i <= num; i++) {
        int sum, part;
        sum= part = i;
        while (part) {
            sum += part % 10;
            part /= 10;
        }
        if (sum == num) {
            cout << i;
            return 0;
        }
    }
    cout << 0;

    return 0;
}
