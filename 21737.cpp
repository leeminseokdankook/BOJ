#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string s;
	stack<int> st;
	char oper='C';
	bool printed=false;
	int number_front_index=0,i,len=0,oper_cnt;
	cin >>oper_cnt>>s;
	for (i = 0; i < s.size() && s[i] >= '0' && s[i] <= '9'; ++i);	//첫 숫자 찾기
	st.push(stoi(s.substr(number_front_index, i)));
	while (i < s.size())
	{
		if (s[i] >= '0' && s[i] <= '9')++len;
		else
		{
			if (oper != 'C')
			{
				int number = stoi(s.substr(number_front_index, len));
				int result = st.top();
				st.pop();
				switch (oper)
				{
				case 'S':
					st.push(result - number);
					break;
				case 'M':
					st.push(result * number);
					break;
				case 'U':
					st.push(result / number);
					break;
				case 'P':
					st.push(result + number);
					break;
				}
			}
				oper = s[i];
				number_front_index = i + 1;
				len = 0;
				if (s[i] == 'C')
				{
					cout << st.top() << " ";
					printed = true;
				}
		}
		++i;
	}
	if (printed==false)
	{
		cout << "NO OUTPUT";
	}
	return 0;
}
