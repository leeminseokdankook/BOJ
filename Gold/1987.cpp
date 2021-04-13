#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int DIR[][2]=
{
    1,0,
    0,1,
    -1,0,
    0,-1
};

bool check(int x, int y, int r, int c)
{
    return x>=0&&x<c&&y>=0&&y<r;
}

int main()
{
    queue<tuple<int ,int ,int, int>> q;
    int r, c,ans=0;
    vector<string> table;
    vector<vector<int>> masks;
    cin>>r>>c;
    masks.resize(r,vector<int>(c));
    table.resize(r);
    for(int i=0;i<r;i++)
    {
        cin>>table[i];
    }
    q.push({0,0,1<<(table[0][0]-'A'),1});
    masks[0][0]=1<<(table[0][0]-'A');
    while(q.empty()==false)
    {
        int x,y,mask, len;
        tie(x,y,mask,len)=q.front();
        q.pop();
        ans=max(ans, len);
        for(int i=0;i<4;i++)
        {
            int ny=y+DIR[i][0];
            int nx=x+DIR[i][1];
            if(check(nx,ny,r,c))
            {
                if((1<<(table[ny][nx]-'A'))&mask)continue;
                if(masks[ny][nx]==(mask|(1<<(table[ny][nx]-'A'))))continue;
                q.push(make_tuple(nx,ny,mask|(1<<(table[ny][nx]-'A')), len+1));
                masks[ny][nx]=mask|(1<<(table[ny][nx]-'A'));
            }
        }
    }
    cout<<ans;
    return 0;
}
