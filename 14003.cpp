#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> lis, ans;
    stack<pair<int ,int>> track;
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        if(track.empty()==true||lis.back()<val)
        {
            lis.push_back(val);
            track.push({lis.size(),val});
        }
        else
        {
            auto iter=lower_bound(begin(lis), end(lis), val);
            *iter=val;
            track.push({static_cast<int>(iter-begin(lis))+1, val});
        }
    }
    for(int l=lis.size();track.empty()==false;track.pop())
    {
        if(track.top().first==l)
        {
            l--;
            ans.push_back(track.top().second);
        }
    }
    cout<<lis.size()<<"\n";
    for(auto iter=rbegin(ans);iter!=rend(ans);iter++)
    {
        cout<<*iter<<" ";
    }
    return 0;
}
