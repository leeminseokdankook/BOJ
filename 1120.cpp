#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main() {
	int ans=INT32_MAX;
	string str1,str2;
	cin >> str1>>stra2;
	for (int j = 0; j < str2.length() - str1.length()+1; j++) {
		int n = 0;
		for (int i = 0; i < str1.length(); i++) {
			if (str1[i] != str2[j + i])n++;
		}
		ans = min(n, ans);
	}
	cout << ans;
	return 0;
}
