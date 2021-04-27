#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Tri
{
    private:
        Tri* children[2];
    public:
        Tri();
        void Add(int val, int digit);
        int Get(int val, int digit);
};

int main()
{
    Tri tri;
    vector<int> arr;
    int n,ans=0;
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
        tri.Add(arr[i], 31);
    }
    for(int i=0;i<n;++i)
    {
        ans=max(ans, tri.Get(arr[i], 31));
    }
    cout<<ans;
    return 0;
}

void Tri::Add(int val, int digit)
{
    //if val has (1<<digit) bit, next -> children[1], else next -> children[0]
    if(digit<0) return;
    bool has_bit=static_cast<bool>(val&(1<<digit));
    int nxt=0;
    if(has_bit)nxt=1;
    if(children[nxt]==nullptr)
    {
        children[nxt]=new Tri();
    }
    children[nxt]->Add(val,digit-1);
}

int Tri::Get(int val, int digit)
{
    if(digit<0)return 0;
    bool has_bit=static_cast<bool>(val&(1<<digit));
    int nxt=1,ret=0;
    if(has_bit)nxt=0;
    //if val has (1<<digit) bit,
    //nxt=0
    //else nxt=1
    if(children[nxt]==nullptr)
    {
        nxt=(nxt+1)%2;
    }
    else
    {
        ret=1<<digit;
    }
    return ret+children[nxt]->Get(val, digit-1);
}

Tri::Tri()
{
    children[0]=children[1]=nullptr;
}
