#include <stack>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while(1){
        int ans=0;
        vector<int> h;
        cin>>n>>m;
        if(n==0&&m==0)
        {
            break;
        }
        h.resize(m);
        for(int i=0;i<n;i++)
        {
            stack<pair<int, int>> st;
            for(int i=0;i<m;i++)
            {
                int height;
                cin>>height;
                h[i]=(h[i]+1)*height;
                if(st.empty())
                {
                    st.push({i,h[i]});
                }
                else
                {
                    if(st.top().second<h[i])
                    {
                        st.push({i,h[i]});
                    }
                    else
                    {
                        int index;
                        while(st.empty()==false&&st.top().second>=h[i])
                        {
                            pair<int ,int> p=st.top();
                            ans=max(ans, p.second*(i-p.first));
                            index=p.first;
                            st.pop();
                        }
                        st.push({index,h[i]});
                    }
                }
            }
            while(st.empty()==false)
            {
                pair<int ,int> p=st.top();
                ans=max(ans, (m-p.first)*p.second);
                st.pop();
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
