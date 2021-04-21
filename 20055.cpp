#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, cnt=0,ans=0;	//cnt -> 내구도가 0인 케이블
	int start, end;
	vector<int> durability;
	vector<bool> isRobot;	//n번 칸에 로봇이 있는가
	queue<int> robot_position;
	cin >> n>>k;
	start = 1, end = n;
	durability.resize(2*n + 1);
	isRobot.resize(2 * n + 1, false);
	for (int i = 1; i <= 2*n; i++) {
		cin >> durability[i];	
	}
	while (cnt < k) {
		ans++;
		//start move_belt
		start=start>1?start-1:2*n;
		end = end > 1 ? end - 1 : 2* n;
		//end move belt

		//move robot
		int loop_cnt = robot_position.size();
		for (int i = 0; i < loop_cnt; i++) {
			int position = robot_position.front();
			isRobot[position] = false;
			robot_position.pop();
			if (position == end) continue;	//현재 칸에서 내려가는 칸이면 내려 감
			int next =  position + 1;
			if (next > 2 * n)next = 1;
			if (durability[next] && !isRobot[next])		//다음 칸에 갈 수 있다면
			{
				durability[next]--;
				if (durability[next] == 0) cnt++;
				if (next != end) {
					robot_position.push(next);
					isRobot[next] = true;
				}
			}
			else
			{
				robot_position.push(position);
				isRobot[position] = true;
			}
		}
		//end move robot

		//start robot place;
		if (!isRobot[start] && durability[start] > 0) {
			durability[start]--;
			if (durability[start] == 0) {
				cnt++;
			}
			isRobot[start] = true;
			robot_position.push(start);
		}
	}
	cout << ans << '\n';
	return 0;
}
