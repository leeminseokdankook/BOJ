#include <queue>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    vector<int> heap;
    int n;
    cin>>n;
    heap.resize(n+1);
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>1;j=j/2)
        {
            heap[j]=heap[j/2];
        }
        heap[1]=i+1;
    }
    heap[n]=1;
    for(int i=1;i<=n;i++)
    {
        cout<<heap[i]<<" ";
    }
    return 0;
}
