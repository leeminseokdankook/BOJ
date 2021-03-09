#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,ans=0;
    vector<int> v;
    scanf("%d", &n);
    v.resize(n);
    for(int i=0;i<n;++i)
    {
        scanf("%d", &v[i]);
    }
    sort(begin(v), end(v));
    for(int i=0;i<n;++i)
    {
        int target=v[i];
        int l=0;
        int r=n-1;
        while(l<r)
        {
            int sum=v[l]+v[r];
            if(sum==target)
            {
                if(l!=i&&r!=i)
                {
                    ++ans;
                    break;
                }
                else if(l==i)
                {
                    ++l;
                }
                else if(r==i)
                {
                    --r;
                }
            }
            else if(sum>target)
            {
                --r;
            }
            else
            {
                ++l;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
