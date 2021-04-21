#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef struct _gasstation{
	int r,c;
	int fuel;
	bool operator<(const struct _gasstation& p){
		return r+c<p.r+p.c;
	}
}gas;

int distance(gas& g1, gas& g2);
bool dirCheck(gas& front, gas& back);
bool solve(int r, int c, vector<gas>& v, int k);
//처음 비용  k로 갈 수 있는가
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<gas> v;
	int r,c, N,left,right;
	cin>>r>>c>>N;
	v.push_back({1,1,0});
	while(N--){
		int x, y,f;
		cin>>y>>x>>f;
		v.push_back({y,x,f});
	}
	v.push_back({r,c,0});
	sort(v.begin(), v.end());
	left=0, right=6000;
	while(left+1<right){
		int mid=(left+right)>>1;
		if(solve(r,c,v,mid))right=mid;
		else left=mid;
	}
	cout<<left;
	// your code goes here
	return 0;
}

int distance(gas& g1, gas& g2){
	return abs(g1.r-g2.r)+abs(g1.c-g2.c);
}

bool dirCheck(gas& front, gas& back){
	return front.r<=back.r&&front.c<=back.c;
}
bool solve(int r, int c, vector<gas>& v, int k){
	//v[0]는 시작 지점
	//v[n+1]은 도착 지점
	vector<int> dp(v.size(),-1);
	int end=v.size();
	//dp[i]는 i번째 노드에 남은 최대 연료
	dp[0]=k;
	for(int i=1;i<end;i++){
		for(int previous=0;previous<i;previous++){
			if(dirCheck(v[previous], v[i])){	//previous에서 i까지 갈 수 있는가
				int cost=distance(v[i],v[previous]);	//previous -> i 까지 비용
				if(dp[previous]>cost){	//이번 노드에 남은 최대 연로로 i까지 갈 수 있다면
					dp[i]=max(dp[i], dp[previous]-cost+v[i].fuel);
				}
			}
		}
	}
	return dp.back()!=-1;
}
