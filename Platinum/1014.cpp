#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;


/*

Baekjoon 1014 트리인가?

입력 형식
테스트케이스 C
세로 N, 가로 M
.은 앉을 수 있는 자리
x는 못 앉는 자리

출력 최대로 앉힐 수 있는 학생 수

조건

학생이 앉은 자리 좌우+전방 대각선엔 못 앉음

풀이

i열의 배치에 따라 i+1의 최대 배치가 바뀜

dp[i](배치열) == -1 이면 -> 해당 배치열은 불가능
dp[i](배치열) = i 열의 배치가 배치열 일때, 최대 학생 수
dp[i](배치열) = max( dp[i-1](배치열)+(현 배치열)

*/

bool CheckRow(int bit, int width);			//좌우 확인
int CountStudet(int bit, int width);					//학생수 확인
bool BitCheck(int back_bit, int front_bit, int width);	//back_bit를 통해 front 비트를 채울 수 있는가
bool PlaceCheck(string& str, int bit);		//해당 비트를 놓을 수 있는가

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int C;
	cin >> C;
	while (C--)
	{
		int N, M, ans=0;
		vector<string> classroom;
		vector<vector<int>> dp;
		list<pair<int, int>> bit_list;		//bit, 학생 수
		cin >> N >> M;
		classroom.resize(N+1);
		for (int i=1;i<=N;i++)
		{
			cin >> classroom[i];
		}
		dp.resize(N+1, vector<int>(1<<M,0));
		for (int i = 0; i < (1 << M); i++)
		{
			if (CheckRow(i, M))
			{
				bit_list.push_back({ i,CountStudet(i,M) });
			}
		}
		//다음 줄 부터 확인
		for (int front = 1; front <= N; front++)
		{
			for (auto& front_bit : bit_list)
			{
				if (PlaceCheck(classroom[front], front_bit.first))
				{
					for (auto& back_bit : bit_list)
					{
						if (BitCheck(back_bit.first, front_bit.first, M))
						{
							dp[front][front_bit.first] = max(dp[front][front_bit.first], dp[front - 1][back_bit.first] + front_bit.second);
							ans = max(dp[front][front_bit.first], ans);
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}

bool CheckRow(int bit, int width)
{
	for (int i = 0; i < width - 1; i++) {
		int val = 3 << i;    //양옆에 앉는 경우 탐색
		if ((val & bit) == val)return false;
	}
	return true;
}

int CountStudet(int bit, int width)
{
	int ret = 0;
	for (int i = 0; i < width; i++)
	{
		if (bit & (1 << i)) ret++;
	}
	return ret;
}

bool BitCheck(int back_bit, int front_bit, int width)
{
	for (int i = 0; i < width; i++)
	{
		if (front_bit & (1 << i))	//앞자리에 있는 놈 뒤에
		{
			if (i > 0 && back_bit & (1 << (i - 1)))		//왼쪽 대각선
			{
				return false;
			}
			if (back_bit & (1 << (i + 1)))
			{
				return false;
			}
		}
	}
	return true;
}

bool PlaceCheck(string& str, int bit)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'x' && (bit & (1 << i)))return false;
	}
	return true;
}