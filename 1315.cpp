#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int Solve(int intell, int str, vector<vector<int>>& dp, vector<tuple<int, int, int>>& q, bool* isClear, int n)
{
    int& ref=dp[intell][str];
    if(ref!=-1)
    {
        return ref;
    }
    vector<int> clear_q;
    int cnt=0,point=0;
    for(int index=0;index<n;++index)
    {

        auto [s,i,p]=q[index];
        if(s<=str||i<=intell)
        {
            ++cnt;    //지금 까지 클리어한 개수
            if(isClear[index]==false)
            {
                //클리어해버림
                isClear[index]=true;
                clear_q.push_back(index);
                point+=p;
            }
        }
    }
    ref=cnt;
    int max_str=min(1000, point+str);
    for(int next_str=str;next_str<=max_str;++next_str)
    {
        ref=max(ref, Solve(min(1000, (intell+point-(next_str-str))),next_str, dp, q,isClear, n));
    }
    for(auto index:clear_q)
    {
        //미완료로 전환
        isClear[index]=false;
    }
    return ref;
}
int main()
{
    vector<vector<int>> dp(1001,vector<int>(1001, -1));
    bool* isClear=nullptr;
    vector<tuple<int, int, int>> q;
    int n;
    cin>>n;
    isClear=new bool[n]{false};
    for(int i=0;i<n;++i)
    {
        int str, intell, point;
        cin>>str>>intell>>point;
        q.push_back({str, intell, point});
    }
    cout<<Solve(1,1,dp,q,isClear,n);
    delete[] isClear;
    return 0;
}
