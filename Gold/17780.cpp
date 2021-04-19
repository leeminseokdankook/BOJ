#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct piece
{
	int dir;
	int x, y;
	bool is_under;	//맨 아래에 있는지 확인
};


int GetColor(int nx, int ny, int board_width, int board_height, 
	vector<vector<int>>& board);	//다음 지점 색 반환
int Reverse_direction(int now_dir);	//방향 전환
bool IsEnd(vector<vector<vector<int>>>& map, vector<piece>& pieces);
int Solution(vector<vector<int>>& board, vector<piece>& pieces);

int main()
{
	int n, k;
	vector<vector<int>> board;
	vector<piece> pieces;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	board.resize(n, vector<int>(n, 0));
	pieces.resize(k);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < k; ++i)
	{
		cin >> pieces[i].y >> pieces[i].x >> pieces[i].dir;
		--pieces[i].y;
		--pieces[i].x;
		pieces[i].is_under = true;
	}
	cout << Solution(board, pieces);
	return 0;
}
int Reverse_direction(int now_dir)
{
	/*
	0->right
	1->left
	2->up
	3->down
	*/
	switch (now_dir)
	{
		case 1:
			return 2;
		case 2:
			return 1;
		case 3:
			return 4;
		case 4:
			return 3;
	}
}

int GetColor(int nx, int ny, int board_width, int board_height,
	vector<vector<int>>& board)
{
	if (ny >= board_height || ny < 0 || nx < 0 || nx >= board_width)
	{
		return 2;
	}
	return board[ny][nx];
}

bool IsEnd(vector<vector<vector<int>>>& map, vector<piece>& pieces)
{
	for (auto& p : pieces)
	{
		if (map[p.y][p.x].size() >= 4)
		{
			
			return true;
		}
	}
	return false;
}


int Solution(vector<vector<int>>& board, vector<piece>& pieces)
{
	int dx[] = { 0,1,-1,0,0 };
	int dy[] = { 0,0,0,-1,1 };
	int time = 0;
	int n = board.size();
	vector<vector<vector<int>>> map(n, vector<vector<int>>(n));
	for (int i = 0; i < pieces.size(); ++i)
	{
		map[pieces[i].y][pieces[i].x].push_back(i);
	}
	while (time <= 1000)
	{
		++time;
		//piece move
		for (int i = 0; i < pieces.size(); ++i)
		{
			if (pieces[i].is_under == false)continue;
			int previous_y = pieces[i].y;
			int previous_x = pieces[i].x;
			int ny = previous_y + dy[pieces[i].dir];
			int nx = previous_x + dx[pieces[i].dir];
			int next_color = GetColor(nx, ny, n, n, board);
			switch (next_color)
			{
				case 0:
				{
					if (map[ny][nx].size() > 0)	//다음 칸이 비어있지 않다면
					{
						pieces[i].is_under = false;
					}
					for (auto piece_number : map[pieces[i].y][pieces[i].x])
					{
						pieces[piece_number].y = ny;
						pieces[piece_number].x = nx;
						map[ny][nx].push_back(piece_number);
					}
					map[previous_y][previous_x].clear();
					break;
				}
				case 1:
				{
					pieces[i].is_under = false;
					if (map[ny][nx].size() == 0)
					{
						pieces[map[previous_y][previous_x].back()].is_under = true;
					}
					for (auto riter = rbegin(map[previous_y][previous_x]); riter != rend(map[previous_y][previous_x]); ++riter)
					{
						map[ny][nx].push_back(*riter);
						pieces[*riter].y = ny;
						pieces[*riter].x = nx;
					}
					map[previous_y][previous_x].clear();
					break;
				}
				case 2:
				{
					pieces[i].dir = Reverse_direction(pieces[i].dir);
					ny = previous_y + dy[pieces[i].dir];
					nx = previous_x + dx[pieces[i].dir];
					switch (GetColor(nx,ny,n,n,board))
					{
						case 0:
							if (map[ny][nx].size() > 0)	//다음 칸이 비어있지 않다면
							{
								pieces[i].is_under = false;
							}
							for (auto piece_number : map[pieces[i].y][pieces[i].x])
							{
								pieces[piece_number].y = ny;
								pieces[piece_number].x = nx;
								map[ny][nx].push_back(piece_number);
							}
							map[previous_y][previous_x].clear();
							break;
						case 1:
						{
							pieces[i].is_under = false;
							if (map[ny][nx].size() == 0)
							{
								pieces[map[previous_y][previous_x].back()].is_under = true;
							}
							for (auto riter = rbegin(map[previous_y][previous_x]); riter != rend(map[previous_y][previous_x]); ++riter)
							{
								map[ny][nx].push_back(*riter);
								pieces[*riter].y = ny;
								pieces[*riter].x = nx;
							}
							map[previous_y][previous_x].clear();
							break;
						}
					}
				}
			}
		}
		if (IsEnd(map, pieces))
		{
			break;
		}
	}
	if (time > 1000)
	{
		return -1;
	}
	return time;
}
