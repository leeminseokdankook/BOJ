#include <stdio.h>

int main() {
	int answer = 0;
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);
	int day = A - B, low = 0, high = V, mid=V/2;
	while (1) {
		answer = mid / day;
		if (V - (answer * day) > A) {
			low = mid;
		}
		else {
			if (mid + A - V >= day) {
				high = mid;
			}
			else {
				break;
			}
		}
		mid = (low + high) >> 1;
	}
	printf("%d", answer + 1);
	return 0;
}
