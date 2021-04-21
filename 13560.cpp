#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> s;
    int n, sum=0;
    bool flag=false;
    cin>>n;
    s.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(s.begin(), s.end());
    for(int i=0;i<n;i++)
    {
        sum+=s[i];
        if(sum<i*(i+1)/2)
        {
            flag=true;
            break;
        }
    }
    if(flag)
    {
        cout<<-1;
    }
    else
    {
        if(sum==n*(n-1)/2)
        {
            cout<<1;
        }
        else
        {
            cout<<-1;
        }
    }
    return 0;
}
