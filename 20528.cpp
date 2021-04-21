#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    char ch;
    string str;
    cin>>n;
        cin>>str;
        ch=str[0];
        for(int i=1;i<n;i++)
        {
            cin>>str;
            if(ch!=str[0])
            {
                cout<<0;
                return 0;
            }
        }
    cout<<1;
    return 0;
}
