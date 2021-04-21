#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n;
    vector<int> cnt(2000001);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        ++cnt[val+1000000];
    }
    for(int i=0;i<=2000000;i++)
    {
        if(cnt[i]==0)continue;
        while(cnt[i]>0)
        {
            --cnt[i];
            cout<<i-1000000<<"\n";
        }
    }
    return 0;
}
