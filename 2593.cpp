#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() 
{
    int N, M, A, B, length = 0,n;
    vector<int> distance, trace;
    vector<bool> visited;   //큐에 들어간 적이 있는가
    queue<int> elevator_queue;
    vector<pair<int, int>> elevators;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    distance.resize(M + 1, INT32_MAX);
    trace.resize(M + 1,-1);
    visited.resize(M + 1, false);
    elevators.resize(M + 1);
    for (int i = 1; i <= M; ++i)
    {
        cin >> elevators[i].first >> elevators[i].second;
    }
    cin >> A >> B;
    //i번째 엘리베이터가 B층을 갈 수 있는지 확인
    for (int i = 1; i <= M; ++i)
    {
        int start = elevators[i].first, gap = elevators[i].second;
        if (start <= B && (B - start) % gap == 0)
        {
            elevator_queue.push(i);
            visited[i] = true;
        }
    }
    while (n = elevator_queue.size())
    {
        ++length;
        while (n--)
        {
            int prevent = elevator_queue.front(); elevator_queue.pop();
            if (elevators[prevent].first <= A &&
                (A - elevators[prevent].first) % elevators[prevent].second == 0)
            {   //현재 뽑은 지점이 A층으로 갈 수 있다면
                cout << length << "\n";
                for (int vertex = prevent; vertex != -1; vertex = trace[vertex])
                {
                    cout << vertex << "\n";
                }
                return 0;
            }
            //갈아 탈  엘리베이터 삽입
            for (int i = 1; i <= M; ++i)
            {
                if (visited[i] == true)continue;
                int source = prevent, dest = i;
                bool flag = false;
                //간격이 더 큰 곳을 기준으로  함
                if (elevators[source].second > elevators[dest].second)
                {
                    swap(source, dest);
                }
                for (int start = elevators[source].first;
                    start <= N; start += elevators[source].second)
                {
                    if (start >= elevators[dest].first &&
                        (start - elevators[dest].first) % elevators[dest].second == 0)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                {
                    trace[i] = prevent;
                    visited[i] = true;
                    elevator_queue.push(i);
                }
            }
        }
    }
    cout << -1;
    return 0;
}
