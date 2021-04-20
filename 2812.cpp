#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<char> ans;
    string str;
    int n,k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    cin>>str;
    for(int i=0;i<n;i++)
    {
        while(k!=0&&ans.size()!=0&&ans.back()<str[i])
        {
            ans.pop_back();
            --k;
        }
        ans.push_back(str[i]);
    }
    while(k!=0)
    {
        ans.pop_back();
        --k;
    }
    for(auto iter=begin(ans);iter!=end(ans);++iter)
    {
        cout<<*iter;
    }
    return 0;
}
