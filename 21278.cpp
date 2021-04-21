#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
using ull=unsigned long long;

int Result(vector<vector<int>>& distance, int s1, int s2, int n);

int main()
{
    vector<vector<int>> distance;
    int n,m,ans=numeric_limits<int>::max();
    int v1,v2;
    cin>>n>>m;
    distance.resize(n+1, vector<int>(n+1, numeric_limits<int>::max()));
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        distance[a][b]=distance[b][a]=1;
    }
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(i==j)
                {
                    distance[i][j]=0;
                    continue;
                }
                if(distance[i][k]!=numeric_limits<int>::max()&&distance[k][j]!=numeric_limits<int>::max())
                {
                    distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
                }
            }
        }
    }
    for(int i=1;i<n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            int val=Result(distance,i,j,n);
            if(ans>val)
            {
                v1=i;v2=j;ans=val;
            }
        }
    }
    cout<<v1<<" "<<v2<<" "<<ans;
    return 0;
}


int Result(vector<vector<int>>& distance, int s1, int s2, int n)
{
    int ret=0;
    for(int i=1;i<=n;++i)
    {
        ret+=min(distance[s1][i]+distance[i][s1], distance[s2][i]+distance[i][s2]);
    }
    return ret;
}
