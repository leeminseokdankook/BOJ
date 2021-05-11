#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string rotation(string& str)
{
    string ret="";
    for(auto iter=crbegin(str);iter!=crend(str);++iter)
    {
        if(*iter=='6')
        {
            ret+='9';
        }
        else if(*iter=='9')
        {
            ret+='6';
        }
        else
        {
            ret+=*iter;
        }
    }
    return ret;
}
bool cmp(string& s1, string& s2);
bool double_print_check(string& obj, string& target)
{
    if(obj.size()!=target.size())
    {
        return obj.size()<target.size();
    }
    else
    {
        return target>obj;
    }
}
int main()
{
    vector<string> arr;
    int n;
    int double_print_index=0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
        arr[i]=rotation(arr[i]);
    }
    for(int i=0;i<n;++i)
    {
        if(double_print_check(arr[double_print_index], arr[i])==true)
        {
            double_print_index=i;
        }
    }
    arr.push_back(arr[double_print_index]);
    sort(begin(arr),end(arr),cmp);
    for(int i=0;i<arr.size();++i)
    {
        arr[i]=rotation(arr[i]);
        cout<<arr[i];
    }
    return 0;
}

bool cmp(string& s1, string& s2)
{
    string target1=s1+s2;
    string target2=s2+s1;
    return target1<target2;
}
