#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans=1;

int TransformFalse(int a)
{
    return (a<<1)|1;
}

int TransformTrue(int a)
{
    return (a<<1);
}
int TransformNot(int a)
{
    return a^1;
}

void dfs(int now, bool* visited, vector<vector<int>>& graph,vector<int>& v);
void dfs(int now, bool* visited, vector<vector<int>>& graph, vector<int>& colors, int color);
void solve(vector<vector<int>>& graph, vector<vector<int>>& rev, int n);

int main()
{
    vector<vector<int>> graph,rev;
    int n,m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    graph.resize(2*n+2);
    rev.resize(2*n+2);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        if(a<0)
        {
            a=TransformFalse(-a);
        }
        else
        {
            a=TransformTrue(a);
        }
        if(b<0)
        {
            b=TransformFalse(-b);
        }
        else
        {
            b=TransformTrue(b);
        }
        graph[TransformNot(b)].push_back(a);
        graph[TransformNot(a)].push_back(b);
        rev[b].push_back(TransformNot(a));
        rev[a].push_back(TransformNot(b));
    }
    solve(graph, rev,n);
    cout<<ans;
    return 0;
}

void dfs(int now, bool* visited, vector<vector<int>>& graph,vector<int>& v)
{
    visited[now]=true;
    for(auto x:graph[now])
    {
        if(visited[x])continue;
        dfs(x, visited, graph, v);
    }
    v.push_back(now);
}

void dfs(int now, bool* visited, vector<vector<int>>& graph, vector<int>& colors, int color)
{
    visited[now]=true;
    colors[now]=color;
    for(auto& x:graph[now])
    {
        if(visited[x])continue;
        dfs(x, visited, graph, colors,color);
    }
}

void solve(vector<vector<int>>& graph, vector<vector<int>>& rev, int n)
{
    int color=1;
    int cnt=(n<<1)+1;
    bool* visited=0;
    vector<int> v,colors(cnt+1);
    visited=new bool[cnt+1]{false};
    for(int i=2;i<=cnt;++i)
    {
        if(visited[i])continue;
        dfs(i,visited, graph, v);
    }
    reverse(v.begin(), v.end());
    delete[] visited;
    visited=new bool[cnt+1]{false};
    for(auto x:v)
    {
        if(visited[x])continue;
        dfs(x,visited,rev, colors,color);
        color++;
    }
    delete[] visited;
    for(int i=1;i<=n;++i)
    {
        if(colors[TransformTrue(i)]==colors[TransformFalse(i)])
        {
            ans=0;
            break;
        }
    }
}
