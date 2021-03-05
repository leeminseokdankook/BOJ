#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int Solve(vector<list<int>>& tree, int start, vector<int>& dp)
{
    int& ref=dp[start];
    if(ref!=-1)
    {
        return ref;
    }
    if(tree[start].size()==0)
    {
        return ref=0;
    }
    vector<int> times;
    for(int v:tree[start])
    {
        times.push_back(Solve(tree,v,dp));
    }
    sort(times.begin(),times.end(), greater<int>());
    for(int i=0;i<times.size();i++)
    {
        ref=max(ref, times[i]+i+1);
    }
    return ref;
}

int main()
{
    vector<list<int>> tree;
    int n;
    vector<int> dp;
    cin>>n;
    tree.resize(n);
    dp.resize(n,-1);
    for(int i=0;i<n;i++)
    {
        int up;
        cin>>up;
        if(up!=-1)
        {
            tree[up].push_back(i);
        }
    }
    cout<<Solve(tree,0,dp);
    return 0;
}
