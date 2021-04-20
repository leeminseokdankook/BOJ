#include <list>
#include <vector>
#include <iostream>
using namespace std;

void DFS(vector<list<int>>& g, vector<int>& markes, int v, int mark, vector<bool>& visited){
    visited[v]=true;
    markes[v]=mark;
    auto last=g[v].end();
    for(auto iter=g[v].begin();iter!=last;iter++){
        if(visited[*iter])continue;
        DFS(g,markes,*iter,3-mark,visited);
    }
}

bool IsOk(vector<list<int>>& g, vector<int>& markes){
    int g_size=g.size();
    for(int index=1;index<g_size;index++){
        auto end=g[index].end();
        for(auto iter=g[index].begin();iter!=end;iter++){
            if(markes[index]==markes[*iter]) return false;
        }
    }
    return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
   vector<list<int>> g;
   vector<bool> visited;
   int K,V,E;
   cin>>K;
   while(K--){
   		vector<list<int>> empty;
   		vector<bool> v;
   		vector<int> mark;
   		visited.swap(v);
   		g.swap(empty);
   		cin>>V>>E;
   		g.resize(V+1,list<int>());
   		visited.resize(V+1,false);
   		mark.resize(V+1, 0);
   		while(E--){
   			int v1,v2;
   			cin>>v1>>v2;
   			g[v1].push_back(v2);
   			g[v2].push_back(v1);
   		}
   		for(int i=1;i<=V;i++){
   			if(mark[i]==0){
   				DFS(g,mark,i,1,visited);
   			}
   		}
   		if(IsOk(g,mark)){
   			cout<<"YES\n";
   		}
   		else{
   			cout<<"NO\n";
   		}
   }
   return 0;
}
