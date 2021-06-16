#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;


int main()
{
    const int MAX=numeric_limits<int>::max();
    vector<vector<int>> matrix;
    vector<int> starting_point;
    vector<int> ans;
    int n,m,k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    matrix.resize(n+1,vector<int>(n+1,MAX));
    while(m--){
        int a,b,x;
        cin>>a>>b>>x;
        matrix[a][b]=x;
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(matrix[i][k]!=MAX&&matrix[k][j]!=MAX){
                    matrix[i][j]=min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                }
            }
        }
    }
    cin>>k;
    while(k--){
        int p;
        cin>>p;
        starting_point.push_back(p);
    }
    int total_max_dis=MAX;
    for(int flow=1;flow<=n;++flow){
        bool flag=false;
        for(int p:starting_point){
            if(matrix[p][flow]==MAX||matrix[flow][p]==MAX){
                flag=true;
                break;
            }
        }
        if(flag){
            continue;
        }
        int max_dis=-1;
        for(int p:starting_point){
            max_dis=max(max_dis, flow==p?matrix[p][p]:(matrix[p][flow]+matrix[flow][p]));
        }
        if(total_max_dis>max_dis){
            ans.clear();
            total_max_dis=max_dis;
        }
        if(ans.empty()==true||total_max_dis==max_dis){
            ans.push_back(flow);
        }
    }
    sort(begin(ans), end(ans));
    for(int p:ans){
        cout<<p<<" ";
    }
    return 0;
}
