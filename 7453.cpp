#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> v1, v2;
	vector<vector<int>> p_v;
	int n;
    long long int ans=0;
	cin >> n;
	v1.resize(n * n); v2.resize(n * n);
	p_v.resize(n, vector<int>(4));
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		p_v[i] = { a,b,c,d };
	}
	for (int i = 0; i < n; i++) {
		int row = i * n;
		for (int j = 0; j < n; j++) {
			v1[row+ j] = p_v[i][0] + p_v[j][1];
			v2[row + j] = p_v[i][2] + p_v[j][3];
		}
	}
	sort(v2.begin(), v2.end());
    sort(v1.begin(), v1.end());
    int s=0, e=n*n-1;
    while(s<n*n&&e>=0)
    {
        if(v1[s]==-v2[e])
        {
            int front_cnt=0, front=v1[s];
            int back_cnt=0, back=v2[e];
            while(s<n*n&&v1[s]==front)
            {
                ++s;
                ++front_cnt;
            }
            while(e>=0&&v2[e]==back)
            {
                --e;
                ++back_cnt;
            }
            ans+=static_cast<long long int>(front_cnt)*back_cnt;
        }
        else
        {
            if(-v1[s]>v2[e])
            {
                   ++s;
            }
            else
            {
                --e;
            }
        }
    }
	cout << ans;
	return 0;
}
