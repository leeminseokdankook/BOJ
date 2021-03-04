#include <iostream>
using namespace std;

int cycle(int init, int pre, int len);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    cout << cycle(N, N, 0);
    return 0;
}

int cycle(int init, int pre, int len) {
    int front = pre / 10;   //이전 수의 10의 자리
    int back = pre % 10;    //이전 수의 1의 자리
    int add = (front + back)%10;
    int result = (back) * 10 + add;
    if (result == init) {
        return len + 1;
    }
    else {
        return cycle(init, result, len + 1);
    }
}

