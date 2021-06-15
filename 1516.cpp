#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int solve(vector<int>& dp, const vector<vector<int>>& tech_tree, const vector<int>& build_time, int target){
    if(dp[target]!=-1){
        return dp[target];
    }
    int& ref=dp[target];
    if(tech_tree[target].size()==0){
        ref=build_time[target];
    }
    else{
        for(int previous_build:tech_tree[target]){
            ref=max(ref, build_time[target]+solve(dp,tech_tree,build_time,previous_build));
        }
    }
    return ref;
}

int main()
{
    vector<vector<int>> tech;
    vector<int> dp, build_time;
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    dp.resize(n+1,-1);
    build_time.resize(n+1);
    tech.resize(n+1);
    for(int i=1;i<=n;++i){
        cin>>build_time[i];
        while(1){
            int previous_build;
            cin>>previous_build;
            if(previous_build==-1){
                break;
            }
            tech[i].push_back(previous_build);
        }
    }
    for(int i=1;i<=n;++i){
        solve(dp,tech,build_time,i);
    }
    for(int i=1;i<=n;++i){
        cout<<dp[i]<<"\n";
    }
    return 0;
}
