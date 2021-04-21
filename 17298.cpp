#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    vector<int> arr,ans;
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    arr.resize(n);
    ans.resize(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    for(int i=n-1;i>=0;--i)
    {
        int val=arr[i];
        while(st.empty()==false&&val>=st.top())
        {
            st.pop();
        }
        if(st.empty())
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=st.top();
        }
        st.push(val);
    }
    for(int& x:ans)
    {
    	cout<<x<<" ";
    }
    return 0;
}
