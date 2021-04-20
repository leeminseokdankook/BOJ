#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> start, finish;
    int n, ans=1;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    start.resize(n);
    finish.resize(n);
    for(int i=0;i<n;++i)
    {
        cin>>start[i]>>finish[i];
    }
    sort(begin(start),end(start));
    sort(begin(finish), end(finish));
    for(int i=0;i<n;++i)
    {
        int k=lower_bound(begin(start), end(start), finish[i])-begin(start);
        //k는 finish[i] 이전까지 시작한 강의 수,
        //finish[i]까지 진행하며 i개의 강의는 이미 종료
        ans=max(ans, k-i);
    }
    cout<<ans;
    return 0;
}
