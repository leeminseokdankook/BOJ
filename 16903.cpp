#include <iostream>
#include <vector>
using namespace std;

class Tri
{
private:
	Tri* children[2];
	int cnt[2];
public:
	Tri();
	void push(int x, int bit=31);
	int get(int x, int bit=31);
	void remove(int x, int bit = 31);
};

int main()
{
	Tri tri;
	int m;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	tri.push(0);
	cin >> m;
	while (m--)
	{
		int i, x;
		cin >> i >> x;
		switch (i)
		{
			case 1:
				tri.push(x);
				break;
			case 2:
				tri.remove(x);
				break;
			case 3:
				int val = tri.get(x);
				cout << val << "\n";
				break;
		}
	}
	return 0;
}

Tri::Tri()
{
	children[0] = children[1] = nullptr;
	cnt[0] = cnt[1] = 0;
}

void Tri::push(int x, int bit)
{
	if (bit < 0)
	{
		return;
	}
	bool and_result = static_cast<bool>(x & (1 << bit));
	if (and_result == false)
	{
		++cnt[0];
		if (children[0] == nullptr)
		{
			children[0] = new Tri();
		}
		children[0]->push(x, bit -1);
	}
	else
	{
		++cnt[1];
		if (children[1] == nullptr)
		{
			children[1] = new Tri();
		}
		children[1]->push(x, bit - 1);
	}
}

int Tri::get(int x, int bit)
{
	if (bit < 0)
	{
		return 0;
	}
	bool and_result = static_cast<bool>(x & (1 << bit));
	if (and_result == false)
	{
		if (children[1] != nullptr)
		{
			return ((1 << bit) | children[1]->get(x, bit - 1));
		}
		else
		{
			return (children[0]->get(x, bit - 1));
		}
	}
	else
	{
		if (children[0] != nullptr)
		{
			return ((1 << bit) | children[0]->get(x, bit - 1));
		}
		else
		{
			return (children[1]->get(x, bit - 1));
		}
	}
}

void Tri::remove(int x, int bit)
{
	if (bit < 0)
	{
		return;
	}
	bool have_bit= static_cast<bool>(x & (1 << bit));
	if (have_bit)
	{
		--cnt[1];
		children[1]->remove(x, bit - 1);
		if (cnt[1] == 0)
		{
			delete children[1];
			children[1] = nullptr;
		}
	}
	else
	{
		--cnt[0];
		children[0]->remove(x, bit - 1);
		if (cnt[0] == 0)
		{
			delete children[0];
			children[0] = nullptr;
		}
	}
}
