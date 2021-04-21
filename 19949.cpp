#include <iostream>
using namespace std;
using ull = unsigned long long;

ull solve(int problem_n, int previous_ans, int continious_cnt, int* answers, int incorrect_n)
{
	if (incorrect_n > 5)
	{
		return 0;
	}
	if (problem_n == 10)
	{
		return 1;
	}
	ull ret = 0LL;
	for (int ans = 1; ans <= 5; ++ans)
	{
		if (ans == previous_ans)
		{
			if (continious_cnt == 2)
			{
				continue;
			}
			else
			{
				ret += solve(problem_n + 1, ans, continious_cnt + 1, answers, incorrect_n + (answers[problem_n] != ans));
			}
		}
		else
		{
			ret += solve(problem_n + 1, ans, 1, answers, incorrect_n + (answers[problem_n] != ans));
		}
	}
	return ret;
}
int main()
{
	int answers[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> answers[i];
	}
	cout << solve(0, 0, 0, answers, 0);
	return 0;
}
