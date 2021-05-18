#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> scores;
    int n,k,r=0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    scores.resize(n);
    for(int& score:scores)
    {
        cin>>score;
        r+=score;
    }
    ++r;
    int l=-1;
    while(l+1<r)
    {
        int mid=(l+r)>>1;
        //합의 최솟값
        int cnt=0,sum=0;
        for(int score:scores)
        {
            sum+=score;
            if(sum>=mid)
            {
                ++cnt;
                sum=0;
            }
        }
        if(cnt>=k)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    cout<<l;
    return 0;
}
