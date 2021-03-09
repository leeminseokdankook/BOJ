#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
using uint=unsigned int;

bool cmp(pair<uint, uint>& p1, pair<uint, uint>& p2)
{
    return p1.first>p2.first;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<uint, vector<uint>, less<uint>> pq;
    vector<pair<uint, uint>> v;
    uint n, ans=0, index=0;
    int dead_line;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
        v[i].first--;
    }
    sort(v.begin(), v.end(),cmp);
    dead_line=n;
    //우선순위큐 마지막 데드라인부터 push
    while(dead_line>=0)
    {
        while(index<n&&dead_line==v[index].first)
        {
            pq.push(v[index].second);
            index++;
        }
        if(pq.empty()==false)
        {
            ans+=pq.top();
            pq.pop();
        }
        dead_line--;
    }
    cout<<ans;
    return 0;
}
