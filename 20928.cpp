#include <iostream>
using namespace std;

int main()
{
	int n, m, index, next_index;
	int s, e, max_e, ans=0;
	int* p=nullptr;
	int* x = nullptr;
	//x[i] -> i번째 인력거가 갈 수 있는 최대 지점
	cin.tie(0);
	cout.tie(0);
	//input
	cin >> n >> m;
	p = new int[n + 1];
	x = new int[n + 1];
	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> x[i];
		x[i] += p[i];
	}
	s = p[1]; e = x[1];
	next_index = 1;
	for (index = 1; index <= n; ++index)
	{
		if (s <= m && m <= e)
		{
			cout << ans;
			return 0;
		}
		if (s <= p[index] && x[index] <= e)continue;	//지금 타고 있는 인력거 보다 멀리 갈 수 없는 인력거는 배제
		if (p[index] <= e && x[index] >= e)				//지금 탄 인력거 보다 멀리 갈 수 있는 인력거가 있을 ㄸ,
		{
			if (x[next_index] <= x[index])
			{
				next_index = index;
			}
		}
		else if (p[index] >= e)							//갈아타야할 상황 발생
		{
			if (x[next_index] >= p[index]) {
				s = p[next_index];
				e = x[next_index];
				ans++;
				index--;
			}
			else
			{
				cout << -1;
				return 0;
			}
		}
	}
	//최종 환승 조회
	if (s<=p[next_index]&&p[next_index] <= e && e <= x[next_index])
	{
		ans++;
		s = p[next_index];
		e = x[next_index];
	}
	if (s <= m && m <= e)
	{
		cout << ans;
	}
	else
	{
		cout << -1;
	}
	return 0;
}
