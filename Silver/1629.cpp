#include <iostream>
#include <vector>
using namespace std;

long long int solve(long long int a, long long int b, long long int c) {
	if (b == 0) {
		return 1;
	}
    long long half=solve(a,b>>1,c)%c;
    long long ret=(half*half)%c;
    if (b & 1LL) {
		return (ret*a)%c;
	}
	else {
		return ret;
	}
}
int main() {
	long long int a, b, c;
	cin >> a >> b >> c;
	cout << solve(a, b, c);
	return 0;
}
