#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll=long long;


ll solution(vector<pair<ll, pair<ll, ll>>>& processes, ll t, map<ll, ll>& dp);
ll total_time(vector<pair<ll, pair<ll, ll>>>& processes, ll priority);

int main()
{
    vector<pair<ll,pair<ll, ll>>> processes;
    vector<ll> ans;
    map<ll, ll> dp;
    int n,q;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>q>>n;
    ans.resize(n);
    for(int i=0;i<n;++i){
        ll a,b,c;
        cin>>a>>b>>c;
        c+=1000000000001LL;
        processes.push_back({a,{b,c}});
    }
    sort(begin(processes),end(processes));
    for(int i=0;i<q;++i){
        ll t;
        cin>>t;
        cout<<solution(processes, t,dp)<<"\n";
    }
    return 0;
}

ll total_time(vector<pair<ll, pair<ll, ll>>>& processes, ll priority){
    //process들의 우선순위가priority 까지 도달할때 까지 걸린 시간의 합을 반환
    ll ret=0;
    for(auto& process:processes){
        ll max_priority=process.second.second;              
        ll min_priority=max_priority-process.second.first+1;
        if(priority<=min_priority){
            ret+=process.second.first;
        }
        else if(priority>min_priority&&priority<=max_priority){
            ret+=(max_priority-priority+1);
        }
    }
    return ret;
}

ll solution(vector<pair<ll, pair<ll, ll>>>& processes, ll t, map<ll, ll>& dp){
    ll l=0, r=4000000000000LL;
    while(l<=r){
        ll mid=(l+r)>>1;
        ll time;
        if(dp.find(mid)!=dp.end()){
            time=dp[mid];
        }
        else{
            time=total_time(processes,mid);
            dp[mid]=time;
        }
        if(time>=t){
            //mid 
            ll compare;
            if(dp.find(mid+1)!=dp.end()){
                compare=dp[mid+1];
            }
            else{
                compare=total_time(processes,mid+1);
                dp[mid+1]=compare;
            }
            if(compare<t){
                int process_cnt=t-compare;
                vector<ll> p_id;
                for(auto& process:processes){
                    if(process.second.second>=mid&&process.second.second-process.second.first<mid){
                        p_id.push_back(process.first);
                    }
                }
                return p_id[process_cnt-1];
            }
            else{
                l=mid+1;
            }
        }
        else{
            r=mid-1;
        }
    }
}
