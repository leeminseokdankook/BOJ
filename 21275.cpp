#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using ull=unsigned long long;


ull transform(char ch)
{
    if(ch>='0'&&ch<='9')
    {
        return ch-'0';
    }
    else if(ch>='a'&&ch<='z')
    {
        return ch-'a'+10;
    }
}

ull Calculate(string str, ull val)
{
    ull ret=0;
    ull start=1;
    for(auto iter=rbegin(str);iter!=rend(str);++iter)
    {
        ret+=transform(*iter)*start;
        start*=val;
    }
    return ret;
}
bool isAble(string str, int val)
{
    ull vaule=(1LL<<63);
    int cnt=0;
    while(vaule!=0LL)
    {
        vaule/=static_cast<ull>(val);
        cnt++;
    }
    if(cnt<str.size())
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    vector<tuple<ull, int ,int>> ans;
    string str_a, str_b;
    int min_a=-1, min_b=-1;
    cin>>str_a>>str_b;
    if(str_a.size()>=64||str_b.size()>=64)
    {
        cout<<"Impossible";
        return 0;
    }
    for(int i=0;i<str_a.size();++i)
    {
        min_a=max(static_cast<int>(transform(str_a[i])), min_a);
    }
    min_a+=1;
    for(int i=0;i<str_b.size();++i)
    {
        min_b=max(static_cast<int>(transform(str_b[i])), min_b);
    }
    min_b+=1;
    min_a=max(2,min_a);
    min_b=max(2,min_b);
    for(int A=min_a;A<=36;++A)
    {
        if(isAble(str_a, A)==false)
        {
            break;
        }
        ull val_A=Calculate(str_a, A);
        for(int B=min_b;B<=36;++B)
        {
            if(A==B)continue;
            if(isAble(str_b, B)==false)
            {
                break;
            }
            if(val_A==Calculate(str_b, B))
            {
                ans.push_back({val_A, A,B});
            }
        }
    }
    if(ans.size()==0)
    {
        cout<<"Impossible";
    }
    else if(ans.size()==1)
    {
        ull v;
        int a,b;
        tie(v,a,b)=ans[0];
        cout<<v<<" "<<a<<" "<<b;
    }
    else
    {
        cout<<"Multiple";
    }
    return 0;
}
