#include <vector>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> v,count(1002);
    int n;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        count[v[i]]++;
    }
    for(int i=0;i<=1000;i++)
    {
        //출력할 수 = i
        if(count[i]==0)continue;
        if(count[i+1]==0)
        {
            while(count[i]>0)
            {
                cout<<i<<" ";
                count[i]--;
            }
        }
        else if(count[i+1]>0)    //i+1이 존재한다면
        {
            int index=-1;
            //i+2중 가장 작은 수를 찾음
            for(int k=i+2;k<=1000;k++)
            {
                if(count[k]>0)
                {
                    index=k;
                    break;
                }
            }
            if(index==-1)
            {
                //i+2 이상의 수가 없다면
                while(count[i+1]>0)
                {
                    cout<<(i+1)<<" ";
                    count[i+1]--;
                }
                while(count[i]>0)
                {
                    cout<<i<<" ";
                    count[i]--;
                }
            }
            else
            {
                while(count[i]>0)
                {
                    cout<<i<<" ";
                    count[i]--;
                }
                cout<<index<<" ";
                count[index]--;
            }
        }
    }
    return 0;
}