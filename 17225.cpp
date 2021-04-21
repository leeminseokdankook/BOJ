#include <iostream>
#include <queue>
using namespace std;
typedef struct order
{
    int t;
    char c;
    int m;
}order;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work_s=0, work_j=0, time_s=0, time_j=0
        ,time=0,number=1;
    queue<order> order_list;
    queue<int> s,j;
    int A,B,N;
    cin>>A>>B>>N;
    while(N--)
    {
        int t,m;
        char c;
        cin>>t>>c>>m;
        order_list.push({t,c,m});
    }
    while(order_list.empty()==false||work_s!=0||work_j!=0)
    {
        //주문 받기
        while(order_list.empty()==false&&order_list.front().t==time)
        {
            if(order_list.front().c=='R')
            {    
                //지수 주문
                work_j+=order_list.front().m;

            }
            else
            {
                //상민
                work_s+=order_list.front().m;
            }
            order_list.pop();
        }
        //선물 가져오고 포장시작
        //상민이 부터
        while(time_s==0&&work_s!=0)
        {
            //포장 시간을 끝냈으면
            work_s--;
            s.push(number++);
            time_s=A;
        }
        while(time_j==0&&work_j!=0)
        {
            work_j--;
            j.push(number++);
            time_j=B;
        }
        time_s=time_s>0?time_s-1:0;
        time_j=time_j>0?time_j-1:0;
        time++;
    }
    cout<<s.size()<<"\n";
    while(s.empty()==false)
    {
        cout<<s.front()<<" ";s.pop();
    }
    cout<<"\n"<<j.size()<<"\n";
    while(j.empty()==false)
    {
        cout<<j.front()<<" ";j.pop();
    }
    return 0;
}
