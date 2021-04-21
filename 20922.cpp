#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> v,cnt(100001);
	int n,k, ans=1;;
	cin>>n>>k;
	v.resize(n);
	for(int i=0;i<n;++i)
	{
	    cin>>v[i];
	}
	auto start_p=begin(v);
	auto end_p=begin(v);
	++cnt[*start_p];
	while(true)
	{
	    ++end_p;
	    if(end_p==end(v))break;
	    ++cnt[*end_p];
	    if(cnt[*end_p]>k)
	    {
	        ans=max(ans, static_cast<int>(end_p-start_p));
	        while(*start_p!=*end_p)
	        {
	            --cnt[*start_p];
	            ++start_p;
	        }
            --cnt[*start_p];
	        ++start_p;
	    }
	}
	ans=max(ans, static_cast<int>(end_p-start_p));
	cout<<ans;
	return 0;
}
