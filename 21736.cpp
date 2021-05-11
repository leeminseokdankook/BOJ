#include <vector>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;

bool check(int x, int y, int n, int m);
int solve(vector<string>& camp, int sx, int sy, int n, int m);
int main()
{
	vector<string> camp;
	int n, m, sy,sx;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	camp.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> camp[i];
		for (int j = 0; j < m; ++j)
		{
			if (camp[i][j] == 'I')
			{
				sy = i;
				sx = j;
			}
		}
	}
	int ans = solve(camp, sx, sy, n, m);
	if (ans == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << ans;
	}
	return 0;
}

int solve(vector<string>& camp, int sx, int sy, int n, int m)
{
	int ret = 0;
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	int dir[][2] =
	{
		1,0,
		-1,0,
		0,1,
		0,-1
	};
	q.push({ sx,sy });
	visited[sy][sx] = true;
	while (q.empty() == false)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (camp[y][x] == 'P')
		{
			++ret;
		}
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];
			if (check(nx, ny, n, m) == true)
			{
				if (visited[ny][nx] == false)
				{
					visited[ny][nx] = true;
					if (camp[ny][nx] != 'X')
					{
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	return ret;
}

bool check(int x, int y, int n, int m)
{
	return x >= 0 && x < m&& y >= 0 && y < n;
}
