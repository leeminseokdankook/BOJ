#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool IsSafely(vector<int>& arr);
void Tracking(int n);
bool Tracking(vector<int>& arr, int n);

int main()
{
    int n;
    scanf("%d", &n);
    Tracking(n);
    return 0;
}

void Tracking(int n)
{
    vector<int> arr;
    Tracking(arr, n);
}

bool Tracking(vector<int>& arr, int n)
{
    if(n==arr.size())
    {
        for(auto x:arr)
        {
            printf("%d", x);
        }
        return true;
    }
    for(int i=1;i<=3;++i)
    {
        arr.push_back(i);
        if(IsSafely(arr))
        {
            if(Tracking(arr,n))
            {
                return true;
            }
        }
        arr.pop_back();
    }
    return false;
}

bool IsSafely(vector<int>& arr)
{
    int n=arr.size()/2;
    int f_e=arr.size()-2;
    int b_e=arr.size()-1;
    for(int i=1;i<=n;++i)
    {
        bool flag=true;
        for(int idx=0;idx<i;++idx)
        {
            if(arr[f_e-idx]!=arr[b_e-idx])
            {
                flag=false;
            }
        }
        if(flag)
        {
            return false;
        }
        --f_e;
    }
    return true;
}
