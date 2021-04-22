#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

bool Check(int x, int y, int w, int h);
void BFS(pair<int, int>& starting_point, vector<vector<char>>& board, vector<vector<int>>& counts,int w,int h);
int main() 
{
    int T;
    cin >> T;
    while (T--)
    {
        int w, h;
        long long ans = numeric_limits<long long>::max();
        vector<vector<char>> board;
        vector<pair<int, int>> starting_points;
        vector<vector<int>> distance[3];
        starting_points.push_back({ 0,0 });
        cin >> h >> w;
        board.resize(h + 2, vector<char>(w + 2,'.'));
        for (int i = 0; i < 3; ++i)
        {
            distance[i].resize(h + 2, vector<int>(w + 2,-1));
        }
        for (int row = 1; row <= h; ++row)
        {
            for (int col = 1; col <= w; ++col)
            {
                cin >> board[row][col];
                if (board[row][col] == '$')
                {
                    starting_points.push_back({ col,row });
                }
            }
        }
        for (int i = 0; i < 3; ++i)
        {
            BFS(starting_points[i], board, distance[i],w,h);
        }
        for (int row = 1; row <= h; ++row)
        {
            for (int col = 1; col <= w; ++col)
            {
                if (board[row][col] == '*')continue;
                long long dis = 0;
                bool flag = false;
                for (int i = 0; i < 3; ++i)
                {
                    if (distance[i][row][col] == -1)
                    {
                        flag = true;
                        break;
                    }
                    dis += distance[i][row][col];
                }
                if (flag)continue;
                if (board[row][col] == '#')
                {
                    dis -= 2;
                }
                ans = min(ans, dis);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

void BFS(pair<int, int>& starting_point, vector<vector<char>>& board, vector<vector<int>>& counts, int w, int h)

{
    int dir[][2] = {
        1,0,
        -1,0,
        0,1,
        0,-1
    };
    deque<pair<int, int>> q;
    vector<vector<bool>> visited;
    visited.resize(h+2, vector<bool>(w+2, false));
    q.push_back(starting_point);
    visited[starting_point.second][starting_point.first] = true;
    counts[starting_point.second][starting_point.first] = 0;
    while (q.empty() == false)
    {
        int y = q.front().second;
        int x = q.front().first;
        q.pop_front();
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if (Check(nx, ny, w, h))
            {
                if (visited[ny][nx])continue;
                visited[ny][nx] = true;
                if (board[ny][nx] == '*')continue;
                if(board[ny][nx]=='#')
                {
                    q.push_back({ nx,ny });
                    counts[ny][nx] = counts[y][x] + 1;
                }
                else
                {
                    q.push_front({ nx,ny });
                    counts[ny][nx] = counts[y][x];
                }
            }
        }
    }
}
bool Check(int x, int y, int w, int h)
{
    return x >= 0 && y >= 0 &&x <= (w+1) && y <= (h+1);
}
