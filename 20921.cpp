#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k,next_n=1, index;
	int* arr=nullptr;
	cin.tie(0);
	cout.tie(0);
	//input
	cin >> n >> k;
	arr = new int[n+1] {0};	//동적 배열 할당과 동시에 0으로 초기화
	index = n;	//
	while (k!=0)
	{
		if (k >=index)
		{
			arr[index] = next_n++;
			--index;
			k = k - index;
		}
		else
		{
			arr[k + 1] = next_n++;
			k = 0;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << (arr[i] == 0 ? next_n++ : arr[i])<<" ";
	}
	delete[] arr;
	return 0;
}
