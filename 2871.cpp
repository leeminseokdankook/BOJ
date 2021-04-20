#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
    char* str=0;
    char* h=0,*s=0;
    stack<int> st[26];
    //h는 희원, s는 상근
    int n, s_index,i;
    cin>>n;
    str=new char[n+1];
    h=new char [(n>>1)+1];
    s=new char[(n>>1)+1];
    cin>>str;
    for(i=0;i<n;i++)
    {
        st[str[i]-'a'].push(i);
    }
    h[n>>1]=s[n>>1]=0;
    s_index=n-1;
    for(int turn=0;turn<(n>>1);turn++)
    {
        //상근이 턴
        while(s_index>=0&&str[s_index]==0)
        {
            s_index--;
        }
        s[turn]=str[s_index];
        st[str[s_index]-'a'].pop();
        str[s_index]=0;
        //희원이 턴
        for(i=0;i<26;i++)
        {
            if(st[i].size())
            {
                h[turn]=str[st[i].top()];
                str[st[i].top()]=0;
                st[i].pop();
                break;
            }
        }
    }
    if(strcmp(h,s)>=0) cout<<"NE\n";
    else cout<<"DA\n";
    cout<<h;
    delete[] s;
    delete[] h;
    delete[] str;
    return 0;
}
