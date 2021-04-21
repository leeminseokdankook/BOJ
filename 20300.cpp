#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	unsigned long long int M=0;
	vector<unsigned long long int> v;
	int N;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	if (N & 1)
	{
		N--;
		M = v.back();
	}
	for (int i = 0; i < N/2; i++)
	{
		M = max(M, (v[i] + v[N-i-1]));
	}
	cout << M;
	return 0;

}
