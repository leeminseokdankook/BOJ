#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int ans=INT32_MIN;
int Cal(int left, int right, char oper);
void Solve(string& s, int index, int n, int cur);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n;
	cin >> n >> s;
	Solve(s, 0, n, 0);
	cout << ans; 
	return 0;
}

int Cal(int left, int right, char oper) {
	switch (oper)
	{
		case '+':return left + right;
		case '-':return left - right;
		case '*':return left * right;
	}
}

void Solve(string& s, int index, int n, int cur) {
	if (index >= n) {
		ans = max(ans, cur);
		return;
	}
	char oper = (index == 0) ? '+' : s[index - 1];
	if (index + 2 < n) {
		int res = Cal(s[index] - '0', s[index + 2] - '0', s[index+1]);
		Solve(s, index + 4, n , Cal(cur, res, oper));
	}
	Solve(s, index + 2, n, Cal(cur, s[index]-'0', oper));
}
