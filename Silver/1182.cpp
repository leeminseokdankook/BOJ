#include <iostream>
using namespace std;


int solve(int* arr, int index, int n, int sum, int target);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, s,* arr = 0;;

    cin >> n>>s;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (s == 0) {
        cout << solve(arr, 0, n, 0, s)-1;
    }
    else {
        cout << solve(arr, 0, n, 0, s);
    }
    return 0;
}


int solve(int* arr, int index, int n, int sum, int target) {
    if (index == n) {
        if (sum == target) {
            return 1;
        }
        else {
            return 0;
        }
    }
    return solve(arr, index + 1, n, sum + arr[index], target) + solve(arr, index + 1, n, sum, target);
}

