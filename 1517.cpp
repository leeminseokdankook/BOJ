#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll=long long;

ll Merge(int l, int r, vector<int>& arr);

ll Sort(vector<int>& arr);

int main()
{
    int n;
    vector<int> arr;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    cout<<Sort(arr);
    return 0;
}

ll Sort(vector<int>& arr)
{
    return Merge(0,arr.size()-1,arr);
}

ll Merge(int l, int r, vector<int>& arr)
{
    if(l==r) return 0;
    if(l+1==r)
    {
        if(arr[l]>arr[r])
        {
            swap(arr[l], arr[r]);
            return 1;
        }
        else return 0;
    }
    int mid=(l+r)>>1;
    ll ret=Merge(l,mid,arr)+Merge(mid+1,r,arr);
    int left_index=l,right_index=mid+1;
    vector<int> temp;
    while(left_index<=mid&&right_index<=r)
    {
        if(arr[left_index]>arr[right_index])
        {
            temp.push_back(arr[right_index]);
            ret+=(mid-left_index+1);
            right_index++;
        }
        else
        {
            temp.push_back(arr[left_index++]);
        }
    }
    while(left_index<=mid)
    {
        temp.push_back(arr[left_index++]);
    }
    while(right_index<=r)
    {
        temp.push_back(arr[right_index++]);
    }
    for(int temp_index=0,arr_index=l;temp_index<temp.size();++temp_index, ++arr_index)
    {
        arr[arr_index]=temp[temp_index];
    }
    return ret;
}
