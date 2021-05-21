#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/********************
 * Use two pointers *
 ********************/
 
int main()
{
    vector<int> liquid;
    int ans[2]={0,0};
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int ph;
        cin>>ph;
        liquid.push_back(ph);
    }
    sort(liquid.begin(), liquid.end());
    int l=0,r=n-1;
    ans[0]=liquid[l];ans[1]=liquid[r];
    int max_val=abs(liquid[l]+liquid[r]);
    while(l<r)
    {
        int sum=(liquid[l]+liquid[r]);
        if(abs(sum)<max_val)
        {
            max_val=abs(sum);
            ans[0]=liquid[l];
            ans[1]=liquid[r];
        }
        if(sum>0)
        {
            r--;
        }
        else
        {
            ++l;
        }
    }
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}
