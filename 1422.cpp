#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string& s1, string& s2)
{
	return s1+s2>s2+s1;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	string p="";
	string temp;
	vector<string> ans;
	cin>>k>>n;
	for(int i=0;i<k;i++)
	{
		cin>>temp;
		if(p.size()<temp.size()||(p.size()==temp.size()&&temp>p))p=temp;
		ans.push_back(temp);
	}
	for(int i=0;i<n-k;i++)
	{
		ans.push_back(p);
	}
	sort(ans.begin(), ans.end(), cmp);
	for(string& s:ans)
	{
		cout<<s;
	}
	return 0;
}
