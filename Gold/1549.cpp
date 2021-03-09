#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, ans;
    long long int diff_min = ~(1LL<<(sizeof(long long int)*8-1));
    vector<long long int> v;
    cin >> N;
    ans = N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        long long int val;
        cin >> val;
        v[i] = val;
    }
    for (int k = N / 2; k > 0; k--) {
        vector<long long int> sum_v;    //sum_v[i]=v[i]+v[i+1]+...+v[i+k-1]
        for (int i = 0; i <= N - k; i++) {
            long long int s = v[i];
            for (int index = 1; index < k; index++) {
                s += v[i + index];
            }
            sum_v.push_back(s);
        }
        for (int i = 0; i < N - k; i++) {
            long long int diff;
            for (int index = i + k; index <= N - k; index++) {
                diff = abs(sum_v[i] - sum_v[index]);
                if (diff_min > diff) {
                    diff_min = diff;
                    ans = k;
                }
            }
        }
        if (diff_min == 0) {
            break;
        }
    }
    cout << ans << '\n' << diff_min;
    return 0;
}
