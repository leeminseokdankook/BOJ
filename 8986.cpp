#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

long long int diff(vector<long long int>& v, long long int interval) {
    long long int ret = 0LL;
    for (int i = 0; i < v.size(); i++) {
        ret += abs(interval * i - v[i]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    long long int left, right,ans=~(1LL<<(sizeof(long long int)*8-1));
    vector<long long int> v;
    cin >> N;
    v.resize(N);
    for (long long int& x : v) {
        cin >> x;
    }
    left = 0LL; right = 1e9;
    while (left + 2 < right) {
        long long int mid_1 = (left * 2LL + right) / 3;
        long long int mid_2 = (left + right * 2LL) / 3;
        if (diff(v, mid_1) < diff(v, mid_2)) {
            right = mid_2;
        }
        else {
            left = mid_1;
        }
    }
    for (long long int i = left; i <= right; i++) {
        ans = min(ans, diff(v, i));
    }
    cout << ans;
    return 0;
}
