#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;

bool check(vector<vector<int>>& map, vector<pair<int, int>>& houses, int min_height, int max_hegiht, int n, int sx, int sy);
int main()
{
    vector<pair<int ,int>> houses;
    vector<int> heights;
    vector<vector<int>> board;
    int n;
    int sx,sy;
    int left,right;
    int ans=numeric_limits<int>::max();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    board.resize(n,vector<int>(n));
    for(int i=0;i<n;++i)
    {
        string row;
        cin>>row;
        for(int j=0;j<row.size();++j)
        {
            switch(row[j])
            {
                case 'K':
                    houses.push_back({j,i});
                    break;
                case 'P':
                    sy=i;
                    sx=j;
                    break;
            }
        }
    }
    for(auto& row:board)
    {
        for(auto& col:row)
        {
            cin>>col;
            heights.push_back(col);
        }
    }
    sort(begin(heights), end(heights));
    heights.erase(unique(begin(heights), end(heights)), end(heights));
    for(left=0,right=0;right<heights.size();++right)
    {
        while(heights[left]<=board[sy][sx]&&board[sy][sx]<=heights[right]
        &&check(board,houses,heights[left],heights[right],n,sx,sy))
        {
            ans=min(ans,heights[right]-heights[left]);
            ++left;
        }
    }
    cout<<ans;
    return 0;
}

bool check(vector<vector<int>>& map, vector<pair<int, int>>& houses, int min_height, int max_hegiht, int n, int sx, int sy)
{
    int dir[][2]=
    {
        1,0,
        -1,0,
        1,1,
        -1,-1,
        -1,1,
        1,-1,
        0,-1,
        0,1
    };
    vector<vector<bool>> visited;
    queue<pair<int ,int>> q;
    if(map[sy][sx]>max_hegiht)return false;
    visited.resize(n,vector<bool>(n,false));
    q.push({sx,sy});
    visited[sy][sx]=true;
    while(q.empty()==false)
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<8;++i)
        {
            int ny=y+dir[i][0];
            int nx=x+dir[i][1];
            if(ny>=n||nx>=n||ny<0||nx<0||map[ny][nx]<min_height||map[ny][nx]>max_hegiht)continue;
            if(visited[ny][nx]==true)continue;
            visited[ny][nx]=true;
            q.push({nx,ny});
            
        }
    }
    for(auto& p:houses)
    {
        if(visited[p.second][p.first]==false)
        {
            return false;
        }
    }
    return true;
}
