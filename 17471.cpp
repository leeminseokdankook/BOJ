#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<int> people;	//인구수
int all_visited;
void Is_Connect(vector<list<int>>& connection, bool who, int& visited, int selected, int start);	//각 선거구가 연결 되었는가
void Is_Connect(vector<list<int>>& connection, bool who, int& visited, int selected);
int Solve(vector<list<int>>& connection);
int Solve(vector<list<int>>& connection, int N, int index, int selected);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	vector<list<int>> connection;
	cin >> N;
	people.resize(N+1);
	connection.resize(N+1);
	for (int i = 1; i <= N; i++) {
		all_visited += 1 << i;
		cin >> people[i];
	}
	for (int i = 1; i <= N; i++) {
		int connect_cnt;
		cin >> connect_cnt;
		for(int n=0;n<connect_cnt;n++)
		{
			int v;
			cin >> v;
			connection[i].push_back(v);
		}
	}
	int ans = Solve(connection);
    if(ans==INT32_MAX){
        cout<<-1;
    }
    else{
        cout<<ans;
    }
	return 0;
}
int Solve(vector<list<int>>& connection) {
	return Solve(connection, connection.size(), 1,2);
}
int Solve(vector<list<int>>& connection, int N, int index, int selected) {
	if (selected - all_visited == 0) {
		return INT32_MAX;
	}
	int ret = INT32_MAX;
	int visited = 0;
	Is_Connect(connection, true, visited, selected);
	Is_Connect(connection, false, visited, selected);
	if ((visited & all_visited) == all_visited) {
		int val[2] = { 0,0 };
		for (int i = 1; i < N; i++) {
			val[(bool)(selected & (1 << i))] += people[i];
		}
		int diff = val[0] > val[1] ? val[0] - val[1] : val[1] - val[0];
		ret = diff > ret ? ret : diff;
	}
	for(int i=index+1;i<N;i++){
		selected += 1 << i;
		ret = min(ret, Solve(connection, N, i, selected));
		selected -= 1 << i;
	}
	return ret;
}

void Is_Connect(vector<list<int>>& connection, bool who, int& visited, int selected, int start)
{
	//각 선거구가 연결 되었는가
	visited += 1 << start;
	for (auto iter = connection[start].begin(); iter != connection[start].end(); iter++) {
		if (((bool)(selected&(1<<*iter))!=who)) continue;
		if (visited & (1 << *iter))continue;
		Is_Connect(connection, who, visited, selected, *iter);
	}
}
void Is_Connect(vector<list<int>>& connection, bool who, int& visited, int selected)
{
	for (int i = 1; i < connection.size(); i++) {
		if ((bool)(selected & (1 << i)) == who) {
			Is_Connect(connection, who, visited, selected,i);
			return;
		}
	}
}

