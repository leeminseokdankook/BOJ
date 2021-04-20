#include <iostream>

using namespace std;


int main() {
	int T, H, W, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &H, &W, &N);
		if (N % H) {
			printf("%d%02d\n", N % H, N / H + 1);
		}
		else {
			printf("%d%02d\n", H , N / H);
		}
	}
	return 0;
}
