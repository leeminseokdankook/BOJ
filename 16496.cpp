#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string& s1, string& s2)
{
    return s1+s2>s2+s1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<string> v;
    int n;
    bool flag=true;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]!="0") flag=false;
    }
    if(flag)
    {
    	cout<<"0";
    }
    else
    {
    	sort(v.begin(), v.end(), cmp);
    	for(auto& str:v)
    	{
        	cout<<str;
    	}
    }
    return 0;
}
