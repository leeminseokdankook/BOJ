#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int, vector<int>> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	int n,val;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		if (max_heap.size() == min_heap.size())
		{
			max_heap.push(val);
		}
		else
		{
			min_heap.push(val);
		}
		if (max_heap.empty() == false && min_heap.empty()==false && max_heap.top() > min_heap.top())
		{
			int front = max_heap.top();
			int back = min_heap.top();
			max_heap.pop();
			min_heap.pop();
			max_heap.push(back);
			min_heap.push(front);
		}
		cout << max_heap.top() << "\n";
	}
	return 0;
}
