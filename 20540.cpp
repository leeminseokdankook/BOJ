#include <iostream>
#include <map>
using namespace std;

int main()
{
   map<char, char> m;
    string input;
    m['I']='E';
    m['N']='S';
    m['T']='F';
    m['P']='J';
    for(auto& p:m)
    {
        m[p.second]=p.first;
    }
    cin>>input;
    for(char ch:input)
    {
        cout<<m[ch];
    }
    return 0;
}
