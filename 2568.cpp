#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    vector<pair<int, int>> connect;
    vector<pair<int, int>> track;
    vector<int> lis, ans;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        connect.push_back({ a,b });
    }
    sort(begin(connect), end(connect));
    for (int i = 0; i < n; ++i)
    {
        if (lis.size()==0||lis.back() < connect[i].second)
        {
            track.push_back({ lis.size(), connect[i].first });
            lis.push_back(connect[i].second);
        }
        else
        {
            auto iter = lower_bound(begin(lis), end(lis), connect[i].second);
            *iter = connect[i].second;
            track.push_back({ static_cast<int>(iter - begin(lis)), connect[i].first });
        }
    }
    for (int track_index = track.size() - 1, lis_index = lis.size() - 1; track_index >= 0; --track_index)
    {
        if (track[track_index].first == lis_index)lis_index--;
        else ans.push_back(track[track_index].second);
    }
    sort(begin(ans), end(ans));
    cout << ans.size() << "\n";
    for (auto& v : ans)
    {
        cout << v << "\n";
    }
    return 0;
}
