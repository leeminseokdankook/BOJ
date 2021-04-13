/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int DIR[][2]={
    1,0,
    0,1,
    -1,0,
    0,-1
};

bool IsAble(int x, int y, int m, int n)
{
    return y<n&&y>=0&&x>=0&&x<m;
}

int main()
{
    queue<pair<pair<int ,int>, pair<int, int>>> q;
    vector<string> board;
    vector<vector<bool>> vistied[2];
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m, ans=-1;
    cin>>n>>m;
    board.resize(n);
    vistied[0].resize(n, vector<bool>(m,false));
    vistied[1].resize(n, vector<bool>(m,false));
    for(int i=0;i<n;++i)
    {
        cin>>board[i];
    }
    q.push({{0,0}, {1,0}});
    while(q.empty()==false)
    {
        auto p=q.front();
        q.pop();
        if(p.first.first==n-1&&p.first.second==m-1)
        {
            ans=p.second.first;
            break;
        }
        if(vistied[p.second.second][p.first.first][p.first.second]) continue;
        vistied[p.second.second][p.first.first][p.first.second]=true;
        for(int i=0;i<4;i++)
        {
            int ny=p.first.first+DIR[i][0];
            int nx=p.first.second+DIR[i][1];
            if(IsAble(nx,ny,m,n)==false)continue;
            if(board[ny][nx]=='1')
            {
                if(p.second.second==0)
                {
                    q.push({{ny,nx},{p.second.first+1, 1}});
                }
            }
            else
            {
                 q.push({{ny,nx},{p.second.first+1, p.second.second}});
            }
        }
    }
    cout<<ans;
    return 0;
}
