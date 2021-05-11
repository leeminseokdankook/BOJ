#include <iostream>
#include <vector>
using namespace std;

using line=struct _line
{
    //f(x)= ax + b
    //x in [p, Infinity)
    long long a,b;
    double p;
    _line(long long _a=0, long long _b=0):
        a(_a),b(_b){
            p=0.0;
        };
};

double get_cross_point(line& l1, line& l2);

int main()
{
    vector<line> lines;
    vector<int> a,b;
    vector<long long> dp;
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    a.resize(n+1);
    b.resize(n+1);
    dp.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;++i)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;++i)
    {
        line new_line(b[i-1], dp[i-1]);
        while(lines.size()>1)
        {
            new_line.p=get_cross_point(new_line,lines.back());
            if(new_line.p<=lines.back().p)
            {
                lines.pop_back();
            }
            else
            {
                break;
            }
        }
        lines.push_back(new_line);
        long long x=a[i];
        int index=lines.size()-1;
        if(x<new_line.p)
        {
            int l=0,r=lines.size()-1;
            while(l+1<r)
            {
                int mid=(l+r)>>1;
                if(x<lines[mid].p)
                {
                    r=mid;
                }
                else
                {
                    l=mid;
                }
            }
            index=l;
        }
        dp[i]=x*lines[index].a+lines[index].b;
    }
    cout<<dp[n];
    return 0;
}

double get_cross_point(line& l1, line& l2)
{
    return static_cast<double>(l2.b-l1.b)/(l1.a-l2.a);
}
