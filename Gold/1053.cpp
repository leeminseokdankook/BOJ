#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<vector<int>>& dp, int l, int r, string& str);

/*
dp[l][r] -> str[l,r]까지 문자열을 팰린드롬으로 바꾸는데 필요한 횟수
*/
int main()
{
	int ans;
	vector<vector<int>> dp;
    string str;
    cin>>str;
    dp.resize(str.size(), vector<int>(str.size(), -1));
    ans=solve(dp,0,str.size()-1, str);
    for(int i=0;i<str.size();i++)
    {
        for(int j=i+1;j<str.size();j++)
        {
			vector<vector<int>> empty;
			dp.swap(empty);
    		dp.resize(str.size(), vector<int>(str.size(), -1));
            swap(str[i], str[j]);
            ans=min(ans, solve(dp, 0, str.size()-1, str)+1);
            swap(str[i], str[j]);
        }
    }
    cout<<ans;
}

int solve(vector<vector<int>>& dp, int l, int r, string& str)
{
    int& ref=dp[l][r];
    if(ref!=-1)
    {
        return ref;
    }
    if(l>=r)
	{
		return 0;	
	}
    ref=min(solve(dp, l+1, r,str)+1, min(solve(dp, l,r-1,str)+1, solve(dp,l+1, r-1,str)+(str[l]!=str[r])));
    return ref;
}