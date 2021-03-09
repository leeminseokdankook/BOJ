#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    int* plugs, * schedules, ans=0;
    cin >> N >> K;
    plugs = new int[N];
    schedules = new int[K];
    memset(plugs, 0, sizeof(int) * N);
    for (int i = 0; i < K; i++) {
        cin >> schedules[i];
    }
    for (int i = 0; i < K; i++) {
        int pre_item = schedules[i];
        bool will_adapt = true;
        for (int j = 0; j < N; j++) {
            if (plugs[j] == pre_item) {
                will_adapt = false;
                break;
            }
        }
        if (!will_adapt) {
            continue;
        }
        for (int j = 0; j < N; j++) {
            if (plugs[j]==0) {
                plugs[j] = pre_item;
                will_adapt = false;
                break;
            }
        }
        if (!will_adapt) {
            continue;
        }
        int item_index = -1,plug_index=0;
        for (int j = 0; j < N; j++) {
            //꼽혀있는 것 중 가장 나중에 쓸 것을 뺌
            int pre = plugs[j], k;
            for (k = i + 1; k < K; k++) {
                if (pre == schedules[k]) {
                    break;
                }
            }
            if (item_index < k) {
                item_index = k;
                plug_index = j;
            }
        }
        ans++;
        plugs[plug_index] = pre_item;
    }
    cout << ans;
    return 0;
}

