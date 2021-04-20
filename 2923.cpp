#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
int main()
{
	int A[MAX+1] = {0}, B[MAX+1] = {0};
	int n, minA=MAX+1,maxA=0, maxB=0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b, ans=-1;
		cin >> a >> b;
		++A[a];
		++B[b];
		minA = min(a, minA);
		maxA = max(a, maxA);
		maxB = max(b, maxB);
		int b_cnt = 0, b_val=maxB+1;
		for (int a_val = minA; a_val <= maxA; ++a_val)
		{
			if (A[a_val] == 0)continue;
			int a_cnt = A[a_val];
			while (a_cnt > 0)
			{
				while (b_cnt == 0)
				{
					b_cnt=B[--b_val];
				}
				ans = max(a_val + b_val, ans);
				int disc = min(b_cnt, a_cnt);
				b_cnt -= disc;
				a_cnt -= disc;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
