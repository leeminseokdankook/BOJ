#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<pair<int, int>, int>& o1, pair<pair<int, int>, int>& o2)
{
    if(o1.first.second==o2.first.second)
    {
        return o1.first.first<o2.first.first;
    }
    return o1.first.second<o2.first.second;
}

int main()
{
    vector<int> storage;
    vector<pair<pair<int, int>, int>> order_list;
    int n,c,m;
    int ans=0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>c;
    storage.resize(n+1);
    cin>>m;
    order_list.resize(m);
    for(int i=0;i<m;++i)
    {
        cin>>order_list[i].first.first>>order_list[i].first.second>>order_list[i].second;
    }
    sort(begin(order_list), end(order_list),cmp);
    for(auto& order:order_list)
    {
        int s=order.first.first;
        int e=order.first.second;
        int cnt=order.second;
        int max_storage=0;
        for(int i=s;i<e;++i)
        {
            max_storage=max(max_storage,storage[i]);
        }
        int delivery=min(cnt,c-max_storage);
        ans+=delivery;
        for(int i=s;i<e;++i)
        {
            storage[i]+=delivery;
        }
    }
    cout<<ans;
    return 0;
}
