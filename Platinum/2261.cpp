#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

/*
풀이 방법
left right로 divide
left와 right중 최소 거리를 찾음
mid를 기준으로 더 짧은 거리를 찾음

*/

int Getdistance(pair<int, int>& p1, pair<int, int>& p2)
{
	int x_dis = p1.first - p2.first;
	int y_dis = p1.second - p2.second;
	return (x_dis * x_dis) + (y_dis * y_dis);
}

bool cmp_x(pair<int, int>& p1, pair<int, int>& p2)
{
	return p1.first < p2.first;
}

bool cmp_y(pair<int, int>& p1, pair<int, int>& p2)
{
	return p1.second < p2.second;
}

int Solve(vector < pair<int, int>>& points, int left, int right);
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector<pair<int, int>> points;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		points.push_back({ x,y });
	}
	sort(points.begin(), points.end(), cmp_x);
	cout << Solve(points, 0, n - 1);
	return 0;
}

int Solve(vector < pair<int, int>>& points, int left, int right)
{
	int point_cnt = (right - left + 1);
	if (point_cnt <= 3)
	{
		int ret = INT32_MAX;
		for (int i = left; i < right; i++)
		{
			for (int j = i + 1; j <= right; j++)
			{
				ret = min(ret, Getdistance(points[i], points[j]));
			}
		}
		return ret;
	}
	int mid = (left + right) >> 1;
	int min_dis = min(Solve(points, left, mid), Solve(points, mid + 1, right));
	vector<pair<int, int>> y_v;
	for (int i = left; i <= right; i++)
	{
		int x_dis = points[i].first - points[mid].first;
		if (x_dis * x_dis < min_dis)
		{
			y_v.push_back(points[i]);
		}
	}
	sort(y_v.begin(), y_v.end(), cmp_y);
	for (int i = 0; i < y_v.size(); i++)
	{
		for (int j = i + 1; j < y_v.size(); j++)
		{
			int y_dis = y_v[j].second - y_v[i].second;
			if (y_dis * y_dis < min_dis)
			{
				min_dis = min(min_dis, Getdistance(y_v[i], y_v[j]));
			}
			else {
				break;
			}
		}
	}
	return min_dis;
}
