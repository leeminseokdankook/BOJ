#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int ans=INT32_MAX;
    vector<int> diameter;
    cin>>n;
    diameter.resize(n);
    for(int i=0;i<n;++i)
    {
        cin>>diameter[i];
    }
    sort(begin(diameter), end(diameter));
    for(int i=0;i<n;++i)
    {
        for(int j=i+3;j<n;++j)
        {
            int prevent_height=diameter[i]+diameter[j];
            int left=i+1;
            int right=j-1;
            while(left<right)
            {
                int gap=prevent_height-(diameter[left]+diameter[right]);
                ans=min(abs(gap), ans);
                if(gap<0)
                {
                    right--;
                }
                else
                {
                    ++left;
                }
            }
        }
        if(ans==0)
        {
            break;
        }
    }
    cout<<ans;
    return 0;
}
