#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	for (const char& ch : s)
	{
		int asc = static_cast<int>(ch);
		int print_cnt = 0;
		while (asc)
		{
			print_cnt += (asc % 10);
			asc /= 10;
		}
		for (int i = 0; i < print_cnt; ++i)
		{
			cout << ch;
		}
		cout << "\n";
	}
}
