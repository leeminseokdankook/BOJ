#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int C;
    cin>>C;
    for(int t=1;t<=C;++t)
    {
        cout<<"Case "<<t<<": ";
        int T_one=0,S_one=0, change=0, 
        swap_z2o=0, swap_o2z=0;
        vector<int> Toneindex, Tzeroindex; 
        string S,T;
        cin>>S;
        cin>>T;
        for(int i=0;i<S.size();++i)
        {
            if(T[i]=='1')++T_one;
            if(S[i]=='1')++S_one;
            else if(S[i]=='?')
            {
                ++change;
                if(T[i]=='1')
                {
                    Toneindex.push_back(i);
                }
                else
                {
                    Tzeroindex.push_back(i);
                }
            }
        }
        if(S_one>T_one)
        {
            //S의 1이 T의 1보다 많으면 불가능
            cout<<-1<<"\n";
            continue;
        }
        else if(S_one==T_one)
        {
           for(auto iter=Toneindex.begin();iter!=Toneindex.end();++iter)
           {
                S[*iter]='1';
            }
            for(auto iter=Tzeroindex.begin();iter!=Tzeroindex.end();++iter)
            {
                if(S_one==T_one)break;
                S[*iter]='0';
            }
        }
        else
        {
            if(S_one<T_one)
            {
                for(auto iter=Toneindex.begin();iter!=Toneindex.end();++iter)
                {
                    if(S_one==T_one)break;
                    S[*iter]='1';
                    ++S_one;
                }
            }
            if(S_one<T_one)
            {
                for(auto iter=Tzeroindex.begin();iter!=Tzeroindex.end();++iter)
                {
                    if(S_one==T_one)break;
                    S[*iter]='1';
                    ++S_one;
                }
            }
        }
        for(int i=0;i<S.size();++i)
        {
            if(S[i]=='1'&&T[i]=='0')++swap_o2z;
            else if(S[i]=='0'&&T[i]=='1')++swap_z2o;
        }
        cout<<change+max(swap_o2z, swap_z2o)<<"\n";
    }
    return 0;
}
