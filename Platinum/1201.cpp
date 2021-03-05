#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr;
    int n,m,k;
    cin>>n>>m>>k;
    arr.resize(n);
    if(m+k-1<=n&&n<=m*k)
    {
        //수열이 존재
        for(int i=0;i<n;i++)
        {
            arr[i]=i+1;
        }
        //오름차순으로 설정
        
        //m개의 그룹으로 쪼갬
        int index=0;
        for(int i=1;i<=m;i++)
        {
            int next=min(index+k,n-m+i);
            reverse(arr.begin()+index, arr.begin()+next);
            index=next;
        }
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<' ';
        }
    }
    else
    {
        cout<<-1;
    }
    return 0;
}

