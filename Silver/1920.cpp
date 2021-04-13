#include <stdio.h>
#include <stdlib.h>
int compare(void* a, void* b);
int find(int* arr, int X, int left, int right);
int main() {
	int* arr = 0, *end;
	int n, X, m;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	end = arr + n;
	for (int* ptr = arr; ptr != end; ptr++) {
		scanf("%d", ptr);
	}
	qsort(arr, n, sizeof(int), compare);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &X);
		printf("%d\n", find(arr, X, 0, n));
	}
	return 0;
}
int compare(void* a, void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;
	if (n1 > n2) {
		return 1;
	}
	else if (n1 < n2) {
		return -1;
	}
	else {
		return 0;
	}
}

int find(int* arr, int X, int left, int right) {
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (arr[mid] == X) return 1;
		if (arr[mid] < X) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return 0;
}
