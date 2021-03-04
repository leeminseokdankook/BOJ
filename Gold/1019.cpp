#include <iostream>
#include <vector>
using namespace std;


void cal(int num, int inc, vector<int>& cnt);
void Solve(int start, int end, int inc, vector<int>& cnt);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    vector<int> cnt(10);
    cin >> N;
    Solve(1, N, 1, cnt);
    for (int i = 0; i < cnt.size(); i++)
    {
        cout << cnt[i] << ' ';
    }
    return 0;
}

void Solve(int start, int end, int inc, vector<int>& cnt)
{
    while (start % 10 && start <= end)
    {
        cal(start, inc, cnt);
        start++;
    }
    if (start > end)
    {
        return;
    }
    while (end % 10 != 9 && start <= end)
    {
        cal(end, inc, cnt);
        end--;
    }
    int count = (end / 10 - start / 10) + 1;
    for (int i = 0; i <= 9; i++)
    {
        cnt[i] += count*inc;
    }
    Solve(start / 10, end / 10, inc * 10, cnt);
}

void cal(int num, int inc, vector<int>& cnt)
{
    while (num)
    {
        cnt[num % 10] += inc;
        num /= 10;
    }
}
