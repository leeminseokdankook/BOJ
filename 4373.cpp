#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
struct _Data
{
    int first_number_index, second_number_index;
    //if store result_of_add,
    //first_number_index
    int val;
    bool operator<(struct _Data& p1)
    {
        if(val!=p1.val)
        {
            return val<p1.val;
        }
        else if(first_number_index!=p1.first_number_index)
        {
            return first_number_index<p1.first_number_index;
        }
        else
        {
            return second_number_index<p1.second_number_index;
        }
    }
};

using namespace std;
using Data=struct _Data;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(1)
    {        
        vector<Data> result_of_add,result_of_sub;
        vector<int> arr;
        int n;
        int ans=numeric_limits<int>::min();
        cin>>n;
        if(n==0)break;
        arr.resize(n);
        for(int i=0;i<n;++i)
        {
            cin>>arr[i];
        }
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                result_of_add.push_back({j,i,arr[i]+arr[j]});
                result_of_sub.push_back({j,i,arr[j]-arr[i]});
                result_of_sub.push_back({i,j,arr[i]-arr[j]});
            }
        }
        sort(begin(result_of_add),end(result_of_add));
        sort(begin(result_of_sub), end(result_of_sub));
        auto add_iter=begin(result_of_add);
        auto sub_iter=begin(result_of_sub);
        while(add_iter!=end(result_of_add)&&sub_iter!=end(result_of_sub))
        {
            if(add_iter->val<sub_iter->val)
            {
               ++add_iter;  
            }
            else if(add_iter->val>sub_iter->val)
            {
                ++sub_iter;
            }
            else
            {
                if((add_iter->first_number_index==sub_iter->first_number_index)||
                (add_iter->first_number_index==sub_iter->second_number_index)||
                (add_iter->second_number_index==sub_iter->first_number_index)||
                (add_iter->second_number_index==sub_iter->second_number_index))
                ++sub_iter;
                else
                {
                    ans=max(ans,arr[sub_iter->first_number_index]);
                    ++sub_iter;
                }
            }
        }
        if(ans==numeric_limits<int>::min())
        {
            cout<<"no solution\n";
        }
        else
        {
            cout<<ans<<"\n";
        }
    }
    return 0;
}
