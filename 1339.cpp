#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n, x=9;
    long long ans=0;
    map<char, int> value;
    vector<int> cnt(26);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        string str;
        cin>>str;
        int val=1;
        for(auto iter=rbegin(str);iter!=rend(str);++iter)
        {
            cnt[*iter-65]+=val;
            val*=10;
        }
    }
    sort(begin(cnt), end(cnt));
    for(auto iter=rbegin(cnt);iter!=rend(cnt);++iter)
    {
        ans+=(*iter)*x;
        --x;
    }
    cout<<ans;
    return 0;
}
