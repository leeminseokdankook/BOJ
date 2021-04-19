#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Trace(int now, vector<int>& trace, vector<int>& arr)
{
    if(trace[now]==now)
    {
        cout<<arr[now]<<" ";
    }
    else
    {
        Trace(trace[now], trace, arr);
        cout<<arr[now]<<" ";
    }
}
int main()
{
    vector<int> dp,trace,arr, lcs, indexes;
    int ans=-1,n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    dp.resize(n,1);
    trace.resize(n);
    arr.resize(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
        trace[i]=i;
    }
    lcs.push_back(arr[0]);
    indexes.push_back(0);
    for(int i=1;i<n;++i)
    {
        if(lcs.back()<arr[i])
        {
            lcs.push_back(arr[i]);
            trace[i]=indexes.back();
            indexes.push_back(i);
        }
        else
        {
            int index=static_cast<int>(lower_bound(begin(lcs), end(lcs), arr[i])-begin(lcs));
            if(index!=0)
            {
                trace[i]=indexes[index-1];
            }
            indexes[index]=i;
            lcs[index]=arr[i];
        }
    }
    cout<<lcs.size()<<"\n";  
    Trace(indexes.back(),trace,arr);
    return 0;
}
