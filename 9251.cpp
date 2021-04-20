#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Memo(string& s1, string& s2, vector<vector<int>>& dp, int i, int j) {
	if (i == 0 || j == 0) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (s1[i - 1] == s2[j - 1]) {
		return dp[i][j] = Memo(s1, s2, dp, i - 1, j - 1) + 1;
	}
	else {
		return dp[i][j] = max(Memo(s1, s2, dp, i - 1, j), Memo(s1, s2, dp, i, j - 1));
	}
}
int main() {
	int temp = 1;
	int result = 0;
	vector<vector<int>> dp;
	string str1,str2;
	cin >> str1;
	cin >> str2;
	dp.resize(str1.length() + 1, vector<int>(str2.length() + 1, -1));
	cout<<Memo(str1, str2, dp, str1.length(), str2.length());
	
	return 0;
}
