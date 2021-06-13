#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> create_prefix_sum(vector<int>& v, int size){
    vector<int> ret;
    for(int i=0;i<size;++i){
        int sum=v[i];
        ret.push_back(sum);
        for(int j=(i+1)%size;(j+1)%size!=i;j=(j+1)%size){
            sum+=v[j];
            ret.push_back(sum);
        }
    }
    return ret;
}

long long counting(vector<int>& prefix_sum, int target){
    long long ret=0;
    auto iter=lower_bound(begin(prefix_sum), end(prefix_sum), target);
    if(*iter==target){
        auto end_iter=upper_bound(begin(prefix_sum),end(prefix_sum), target);
        ret=static_cast<long long>(end_iter-iter);
    }
    return ret;
}

int main()
{
    vector<int> A_prefix_sum, B_prefix_sum;
    vector<int> A,B;
    int size;
    int n,m;
    int A_max=0, B_max=0;
    long long ans=0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>size>>m>>n;
    for(int i=0;i<m;++i){
        int pizza_size;
        cin>>pizza_size;
        A.push_back(pizza_size);
        A_max+=pizza_size;
    }
    for(int i=0;i<n;++i){
        int pizza_size;
        cin>>pizza_size;
        B.push_back(pizza_size);
        B_max+=pizza_size;
    }
    A_prefix_sum=create_prefix_sum(A,m);
    B_prefix_sum=create_prefix_sum(B,n);
    A_prefix_sum.push_back(A_max);
    B_prefix_sum.push_back(B_max);
    sort(begin(A_prefix_sum), end(A_prefix_sum));
    sort(begin(B_prefix_sum), end(B_prefix_sum));
    ans+=counting(A_prefix_sum,size);
    ans+=counting(B_prefix_sum,size);
    for(int i=0;i<A_prefix_sum.size();++i){
        int target=size-A_prefix_sum[i];
        if(target<=0)
            break;
        ans+=counting(B_prefix_sum, target);
    }
    cout<<ans;
    return 0;
}
