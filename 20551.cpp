#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    vector<long long> v;
    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    while(m--)
    {
        long long val;
        cin>>val;
        int k=lower_bound(v.begin(), v.end(), val)-v.begin();
        cout<<((k<n&&v[k]==val)?k:-1)<<"\n";
    }
    return 0;
}
