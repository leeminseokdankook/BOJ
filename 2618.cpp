#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
백준 

dp[i][j]=1번 순찰차가 i번 사건을, 2번 순찰차가 j번 사건을 처리 했을 때
마지막 사건을 처리하는 데 남은 최소 거리
dp[i][j]=dp[next][j]+distance(point[i], point[next]), dp[i][next]+distance(point[j], point[next]
*/

int Solve(vector<vector<int>>& dp, vector<vector<pair<int ,int>>>& points, int& w, int i, int j);
void trace(vector<vector<int>>& dp, vector<vector<pair<int, int>>>& points, int& w, int i, int j);
int GetDistance(pair<int, int>& p1, pair<int, int>& p2);


int main()
{
	int n,w, x,y;
	vector<vector<int>> dp;
	vector<vector<pair<int, int>>> points;
	vector<int> who;
	cin >>n>> w;
	points.resize(2, vector<pair<int, int>>(w+1));
	who.resize(w + 1);
	dp.resize(w + 1, vector<int>(w + 1, -1));
	points[0][0] = { 1,1 };
	points[1][0] = { n,n };
	for (int i = 1; i <= w; i++)
	{
		cin >> y >> x;
		points[0][i] = points[1][i]={ x,y };
	}
	cout<<Solve(dp, points, w, 0, 0)<<'\n';
	trace(dp, points, w, 0, 0);
	return 0;
}


int GetDistance(pair<int, int>& p1, pair<int, int>& p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int Solve(vector<vector<int>>& dp, vector<vector<pair<int, int>>>& points,int& w, int i, int j)
{
	/*
	i -> 1번 순찰차가 마지막에 처리한 사건
	j -> 2번 순찰차가 마지막에 처리한 사건
	*/
	int next = max(i, j) + 1;
	int& cache = dp[i][j];
	if (cache != -1) return cache;
	if (i == w || j == w) return cache=0;	//이전에 마지막 사건을 처리
	int dist1 = Solve(dp, points, w, next, j)+GetDistance(points[0][i], points[0][next]);
	int dist2 = Solve(dp, points, w, i, next) + GetDistance(points[1][j], points[1][next]);
	return cache = min(dist1, dist2);
}

void trace(vector<vector<int>>& dp, vector<vector<pair<int, int>>>& points, int& w, int i, int j)
{
	int next = max(i, j) + 1;
	if (next > w)
	{
		return;
	}
	int dist1 = Solve(dp, points, w, next, j) + GetDistance(points[0][i], points[0][next]);
	int dist2 = Solve(dp, points,  w, i, next) + GetDistance(points[1][j], points[1][next]);
	if (dist1 < dist2)
	{
		cout << 1 << '\n';
		trace(dp, points, w, next, j);
	}
	else
	{
		cout << 2 << '\n';
		trace(dp, points, w, i, next);
	}
}
