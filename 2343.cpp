#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans = ~(1<<(sizeof(int)*8-1)), left=0, right=0, n ,m,*lessons=0;
    cin >> n>>m;
    lessons = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> lessons[i];
        right += lessons[i];
        left = left < lessons[i] ? lessons[i] : left;
    }
    
    while (left <= right) {
        int mid = (left + right) >> 1;
        int sum = 0,cnt=1;
        for (int i = 0; i < n; i++) {
            sum += lessons[i];
            if (sum > mid) {
                cnt++;
                sum = lessons[i];
            }
        }
        if (cnt > m) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
            if (ans > mid) {
                ans = mid;
            }
        }
    }
    cout << ans;
    return 0;
}
