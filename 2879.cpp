#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    vector<int> gap;
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    gap.resize(n);
    for(int& g:gap)
    {
        cin>>g;
    }
    for(int& g:gap)
    {
        int result;
        cin>>result;
        g=result-g;
    }
    if(n==0)
    {
        cout<<abs(gap[0]);
    }
    else
    {
        int previous=gap[0];
        int ans=0;
        for(int i=1;i<n;++i)
        {
            if(gap[i]>=0)
            {
                if(previous<0)
                {
                    ans+=abs(previous);
                    previous=gap[i];
                }
                else if(previous<gap[i])
                {
                    previous=gap[i];
                }
                else
                {
                    ans+=previous-gap[i];
                    previous=gap[i];
                }
            }
            else
            {
                if(previous>0)
                {
                    ans+=abs(previous);
                    previous=gap[i];
                }
                else if(previous>gap[i])
                {
                    previous=gap[i];
                }
                else
                {
                    ans+=abs(previous)-abs(gap[i]);
                    previous=gap[i];
                }
            }
        }
        ans+=abs(previous);
        cout<<ans;
    }
    return 0;
}
