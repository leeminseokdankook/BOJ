#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<pair<int, int>> expression;
    int n,m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin>>a>>b;
        expression.push_back({a,b});
    }
    for(int i=0;i<(1<<(n+1));++i)
    {
        bool flag=true;
        for(auto& p:expression)
        {
            bool result=false;
            if(p.first<0)
            {
                result|=!(static_cast<bool>((1<<(-p.first))&i));
            }
            else
            {
                result|=static_cast<bool>((1<<(p.first))&i);
            }
            if(p.second<0)
            {
                result|=!(static_cast<bool>((1<<(-p.second))&i));
            }
            else
            {
                result|=static_cast<bool>((1<<(p.second))&i);
            }
            flag&=result;
        }
        if(flag)
        {
            cout<<1;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
