#include <iostream>
#include <vector>
#include <list>
using namespace std;


int DFS(vector<list<int>>& graph, vector<bool>& visited, int next);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<list<int>> graph;
    vector<bool> visited;
    int n, root, del;
    cin >> n;
    graph.resize(n);
    visited.resize(n, false);
    for (int i = 0; i < n; i++) {
        int par;
        cin >> par;
        if (par == -1) {
            root = i;
        }
        else {
            graph[i].push_back(par);
            graph[par].push_back(i);
        }
    }
    cin >> del;
    visited[del] = true;
    if (del == root) {
        cout << 0;
    }
    else {
        cout << DFS(graph, visited, root);
    }
    return 0;
}
int DFS(vector<list<int>>& graph, vector<bool>& visited, int next) {
    visited[next] = true;
    bool child_flag = false;
    int ret = 0;
    for (list<int>::iterator iter = graph[next].begin(); iter != graph[next].end(); iter++) {
        if (visited[*iter])continue;
        visited[*iter]=true;
        ret += DFS(graph, visited, *iter);
        child_flag = true;
    }
    if (child_flag) {
        return ret;
    }
    else {
        return 1;
    }
}