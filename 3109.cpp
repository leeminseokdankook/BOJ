#include <iostream>
#include <vector>
using namespace std;

bool Check(int x, int y, int r, int c)
{
    return (x>-1&&x<c&&y>-1&&y<r);
}
bool DFS(vector<string>& graph, int x, int y, 
         int r,int e,vector<vector<bool>>& visited, vector<pair<int, int>>& dir, int& answer);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r,c,answer=0;
    vector<pair<int, int>> dir=
    {
        {1,-1},
        {1,0},
        {1,1}
    };
    vector<string> graph;
    vector<vector<bool>> visited;
    cin>>r>>c;
    graph.resize(r);
    visited.resize(r,vector<bool>(c,false));
    for(int i=0;i<r;i++)
    {
        cin>>graph[i];
    }
    for(int i=0;i<r;i++)
    {
        DFS(graph,0,i,r,c,visited,dir,answer);
    }
    cout<<answer;
    return 0;
}

bool DFS(vector<string>& graph, int x, int y, 
         int r,int c,vector<vector<bool>>& visited, vector<pair<int, int>>& dir, int& answer)
{
    visited[y][x]=true;
    if(x==c-1)
    {
        answer++;
        return true;
    }
    for(int i=0;i<3;i++)
    {
        int next_y=dir[i].second+y;
        int next_x=dir[i].first+x;
        if(Check(next_x,next_y,r,c))
        {
        	if(graph[next_y][next_x]=='x')continue;
            if(visited[next_y][next_x]==false)
            {
                if(DFS(graph, next_x,next_y,r,c,visited,dir,answer))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
