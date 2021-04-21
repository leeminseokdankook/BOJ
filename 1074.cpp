#include <iostream>
#include <cmath>
using namespace std;

int Z(int r, int c, int N, int x, int y, int start);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, r, c;
    cin >> N>>r>>c;
    cout << Z(r,c,N,0,0,0);
    return 0;
}

int Z(int r, int c, int N, int x, int y, int start) {
    if (N==1) {
        if (x + 1 == c) {
            if (y + 1 == r) {
                return start + 3;
            }
            else if(y==r) {
                return start + 1;
            }
        }
        else if(x==c){
            if (y + 1 == r) {
                return start + 2;
            }
            else if (y == r) {
                return start;
            }
        }
    }
    else {
        int temp = pow(2, N - 1);
        int add = pow(4, N - 1);
        if (c < x + temp) {
            if (r < y + temp) {
                return Z(r, c, N - 1, x, y, start);
            }
            else {
                return Z(r, c, N - 1, x, y + temp, start + add*2);
            }
        }
        else {
            if (r < y + temp) {
                return Z(r, c, N - 1, x+temp, y, start+add);
            }
            else {
                return Z(r, c, N - 1, x+temp, y + temp, start + add * 3);
            }
        }
    }
}
