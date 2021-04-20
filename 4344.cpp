#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, *score;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int peo, sum=0, high=0;
		double avg;
		cin >> peo;
		score = new int[peo];
		for (int n = 0; n < peo; n++) {
			cin >> score[n];
			sum += score[n];
		}
		avg = (double)sum / peo;
		for (int n = 0; n < peo; n++) {
			if (avg < (double)score[n]) {
				high++;
			}
		}
		printf("%.3lf%%\n", ((double)high / peo)*100);
		delete[] score;
	}
	return 0;
}

