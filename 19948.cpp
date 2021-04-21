#include <iostream>
#include <vector>
using namespace std;

int alpha[26];
int space_cnt;

bool IsUpper(const char ch);
bool CanPush(const char ch);
void Push(const char ch);

int main()
{
    vector<char> ans;

    char ch;
    bool isinit;
    string str;
    getline(cin,str);
    cin>>space_cnt;
    for(int i=0;i<26;++i)
    {
        cin>>alpha[i];
    }
    isinit=true;
    for(int i=0;i<str.size();)
    {
        ch=str[i];
        if(CanPush(ch)==false)
        {
            cout<<-1;
            return 0;
        }
        Push(ch);
        if(isinit)
        {
            ans.push_back(IsUpper(str[i])?str[i]:str[i]-static_cast<char>(32));
            isinit=false;
        }
        while(i<str.size()&&ch==str[i])
        {
            ++i;
        }
        if(ch==' ')
        {
            isinit=true;
        }
    }
    for(auto& ch:ans)
    {
        if(CanPush(ch)==false)
        {
            cout<<-1;
            return 0;
        }
    }
    for(auto& ch:ans)
    {
        cout<<static_cast<char>(ch);
    }
    return 0;
}

void Push(const char ch)
{
    if(ch==' ')
    {
        --space_cnt;
    }
    else
    {
        --alpha[IsUpper(ch)?ch-'A':ch-'a'];

    }
}

bool CanPush(const char ch)
{
    if(ch==' ')
    {
        return space_cnt>0;
    }
    if(IsUpper(ch))
    {
        return alpha[ch-'A']>0;
    }
    else
    {
        return alpha[ch-'a']>0;
    }
}

bool IsUpper(const char ch)
{
    return ch>='A'&&
        ch<='Z';
}
