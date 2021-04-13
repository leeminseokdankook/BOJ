#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, ans=-1;
    vector<int> v(10001);
    scanf("%d", &n);
    for(int i=0;i<n;++i)
    {
        int val;
        scanf("%d", &val);
        ++v[val];
    }
    for(int i=1;i<=10000;++i)
    {
        if(v[i])
        {
            ans=max(ans, n*i);
            n-=v[i];
        }
    }
    printf("%d", ans);
    return 0;
}
