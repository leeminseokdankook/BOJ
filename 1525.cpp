#include <iostream>
#include <queue>
#include <map>
using namespace std;

const int DIR[][2]={
    0,1,
    0,-1,
    1,0,
    -1,0
};

bool check(int ny, int nx);
int main()
{
    const int GOAL=123456789;
    map<int, bool> visited;
    queue<pair<int, int>> q;
    string input;
    int ans=-1;
    for(int i=0;i<9;++i){
        int a;
        cin>>a;
        if(a==0){
            a=9;
        }
        input.push_back(a+'0');
    }
    int start=stoi(input);
    q.push({start,0});
    visited[start]=true;
    while(q.empty()==false){
        int prevent=q.front().first;
        int cnt=q.front().second;
        int void_x, void_y;
        q.pop();
        if(prevent==GOAL){
            ans=cnt;
            break;
        }
        int board[3][3];
        for(int i=2;i>=0;--i){
            for(int j=2;j>=0;--j){
                board[i][j]=prevent%10;
                prevent/=10;
                if(board[i][j]==9){
                    void_x=j;
                    void_y=i;
                }
            }
        }
        for(int i=0;i<4;++i){
            int ny=void_y+DIR[i][0];
            int nx=void_x+DIR[i][1];
            if(check(ny,nx)==true){
                swap(board[ny][nx], board[void_y][void_x]);
                //convert
                int next=0;
                for(int row=0;row<3;++row){
                    for(int col=0;col<3;++col){
                        next*=10;
                        next+=board[row][col];
                    }
                }
                swap(board[ny][nx], board[void_y][void_x]);
                if(visited.find(next)!=visited.end())continue;
                visited[next]=true;
                q.push({next,cnt+1});
            }
        }
    }
    cout<<ans;
    return 0;
}

bool check(int ny, int nx){
    return ny>=0&&ny<3&&nx>=0&&nx<3;
}
