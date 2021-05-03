#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
/*
1. pick k by binary search
2. Create MST by using cost+ k* time , (F>=sigma cost + sigma k*time -> condition(1))
2. if condition(1) is true, left=mid, else right=mid

*/
int find(int x, vector<int>& roots);    //find root of vertex x

bool merge(int x, int y, vector<int>& roots);
//if sucess merge x and y, return true
//else return false

bool check(vector<pair<pair<int, int>, pair<double, double>>>& edges, double k, int n, double f);
int main()
{
    int n, m;
    vector<pair<pair<int, int>, pair<double, double>>> edges;
    double left, right, f;
    //first.first and second -> vertexes
    //second.first -> cost, second.second -> time
    cin >> n >> m >> f;
    edges.resize(m);
    for (int i = 0; i < m; ++i)
    {
        auto& edge = edges[i];
        cin >> edge.first.first >> edge.first.second
            >> edge.second.first >> edge.second.second;
    }
    left = 0.0; right = 2e10;
    for (int i = 0; i < 100; ++i)
    {
        double mid = (left + right) / 2.0;
        if (check(edges, mid, n, f) == true)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    cout << fixed << setprecision(4) << right;
    return 0;
}

int find(int x, vector<int>& roots)
{
    if (roots[x] == x)return x;
    return roots[x] = find(roots[x], roots);
}

bool merge(int x, int y, vector<int>& roots)
{
    int root_of_x = find(x, roots);
    int root_of_y = find(y, roots);
    if (root_of_x == root_of_y)return false;
    roots[root_of_x] = root_of_y;
    return true;
}

bool check(vector<pair<pair<int, int>, pair<double, double>>>& edges, double k, int n, double f)
{
    vector<int> roots(n + 1);
    double sum = 0.0;
    for (int i = 1; i <= n; ++i)
    {
        roots[i] = i;
    }
    sort(begin(edges), end(edges),
        [&k](pair<pair<int, int>, pair<double, double>>& p1, pair<pair<int, int>, pair<double, double>>& p2)->bool
        {return p1.second.first + k * p1.second.second < p2.second.first + p2.second.second * k; });
    for (auto& edge : edges)
    {
        int v1 = edge.first.first, v2 = edge.first.second;
        double time = edge.second.second, cost = edge.second.first;
        if (merge(v1, v2, roots) == true)
        {
            sum += (cost + k * time);
        }
    }
    return (double)f >= sum;
}
