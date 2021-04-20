#include <iostream>
#include <queue>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	priority_queue<int, vector<int>> minous_q;
	priority_queue<int, vector<int>, greater<int>> plus_q;
	cin >> n;
	while (n--)
	{
		int val;
		cin >> val;
		if (val < 0)
		{
			minous_q.push(val);
		}
		else if (val > 0)
		{
			plus_q.push(val);
		}
		else
		{
			if (plus_q.empty() == true && minous_q.empty() == true)
			{
				cout << 0 << "\n";
			}
			else if (plus_q.empty() == true)
			{
				cout << minous_q.top() << "\n";
				minous_q.pop();
			}
			else if (minous_q.empty() == true)
			{
				cout << plus_q.top() << "\n";
				plus_q.pop();
			}
			else
			{
				if (abs(minous_q.top()) <= plus_q.top())
				{
					cout << minous_q.top() << "\n";
					minous_q.pop();
				}
				else
				{
					cout << plus_q.top() << "\n";
					plus_q.pop();
				}
			}
		}
	}
	return 0;
}
