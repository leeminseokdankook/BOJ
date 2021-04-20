#include <vector>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    vector<bool> visited;
    vector<int> cycle_start;
    int n;
    cin>>n;
    v.resize(n);
    visited.resize(n,false);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    //싸이클 확인
    for(int i=0;i<n;i++)
    {
        if(visited[i]) continue;
        int index=i;
        cycle_start.push_back(i);    //싸이클의 시작점 push
        do
        {
            visited[index]=true;
            index=v[index];
        }while(visited[index]==false);
    }
    if(cycle_start.size()>1)
    {    //2개 이상의 사이클이 있으면 완벽한 순열이 아님
        int front=cycle_start[0], back;
        //첫 싸이클을 끊을 위치를 선정
        while(cycle_start[0]!=v[front]&&v[front]<cycle_start[1])
        {
            front=v[front];
        }
        back=v[front];
        for(int i=1;i<cycle_start.size();i++)
        {
            v[front]=cycle_start[i];
            for(front=cycle_start[i];cycle_start[i]!=v[front];front=v[front]);
        }
        v[front]=back;
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
