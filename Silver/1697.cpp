#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    bool visited[200001]{ false };
    queue<int> q;
    int n, k, time=0;
    cin >> n >> k;
    q.push(n);
    while (true)
    {
        int size = q.size();
        bool flag = false;
        for (int i = 0; i < size; ++i)
        {
            int p = q.front();
            q.pop();
            if (p == k)
            {
                flag = true;
                break;
            }
            if (p - 1 >= 0 && visited[p - 1]==false)
            {
                visited[p - 1] = true;
                q.push(p - 1);
            }
            if (p + 1 <= 200000 && visited[p + 1] == false)
            {
                visited[p + 1] = true;
                q.push(p + 1);
            }
            if (2 * p <= 200000 && visited[2 * p] == false)
            {
                visited[p<<1] = true;
                q.push(p<<1);
            }
        }
        if (flag)
        {
            break;
        }
        ++time;
    }
    cout << time;
    return 0;
}
