#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Data=struct _Data
{
    int distance_to_a,distance_to_b;
    int k;
};
using ll=long long;

bool cmp(Data& d1, Data& d2);
ll get_ballon(int k, int& default_ballon_cnt, int& other_ballon_cnt,
    int default_distance, int other_distance);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(true)
    {
        int n,a,b;
        ll ans=0;
        vector<Data> arr;
        cin>>n>>a>>b;
        if(n==0&&a==0&&b==0)break;
        arr.resize(n);
        for(auto& data:arr)
        {
            cin>>data.k>>data.distance_to_a>>data.distance_to_b;
        }
        sort(begin(arr), end(arr), cmp);
        for(auto& data:arr)
        {
            int distance_to_a=data.distance_to_a;
            int distance_to_b=data.distance_to_b;
            int k=data.k;
            if(distance_to_a<distance_to_b)
            {
                ans+=get_ballon(k,a,b,distance_to_a,distance_to_b);   
            }
            else
            {
                ans+=get_ballon(k,b,a,distance_to_b,distance_to_a);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

ll get_ballon(int k, int& default_ballon_cnt, int& other_ballon_cnt,
    int default_distance, int other_distance)
    {
        ll ret=0;
        int using_ballon_cnt=min(k,default_ballon_cnt);
        k-=using_ballon_cnt;
        default_ballon_cnt-=using_ballon_cnt;
        ret+=(static_cast<ll>(using_ballon_cnt)*default_distance);
        if(k!=0)
        {
            other_ballon_cnt-=k;
            ret+=(static_cast<ll>(k)*other_distance);
        }
        return ret;
    }

bool cmp(Data& d1, Data& d2)
{
    int dis_1=abs(d1.distance_to_b-d1.distance_to_a);
    int dis_2=abs(d2.distance_to_b-d2.distance_to_a);
    return dis_1>dis_2;
}
