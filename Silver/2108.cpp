#include <iostream>
#include <vector>
#include <cmath>
#include <queue>;
#include <algorithm>
using namespace std;

int Arithmetic_Mean(vector<int>& v);
int median(vector<int>& v);
int mode(vector<int>& v);
int range(vector<int>& v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	vector<int> v;
	cin >> N;
	v.resize(N);
	for (int& x : v) {
		cin >> x;
	}
	sort(v.begin(), v.end());
	cout << Arithmetic_Mean(v)<<'\n';
	cout << median(v)<<'\n';
	cout << mode(v) << '\n';
	cout << range(v) << '\n';
	return 0;
}

int Arithmetic_Mean(vector<int>& v) {
	double ret;
	int sum = 0;
	for (int x : v) {
		sum += x;
	}
	ret = (double)sum / v.size();
	ret = round(ret);
	return (int)ret;
}

int median(vector<int>& v) {
	return v[v.size() / 2];
}


int mode(vector<int>& v) {
	int index = 0;
	int max_cnt=-1;
	queue<int> q;
	while (index < v.size()) {
		int cnt = 0;
		int obj = v[index];
		index++;
		while (index<v.size()&&v[index] == obj) {
			cnt++;
			index++;
		}
		if (max_cnt < cnt) {
			max_cnt = cnt;
			queue<int> emp;
			q.swap(emp);
			q.push(obj);
		}
		else if(max_cnt==cnt){
			q.push(obj);
		}
	}
	if (q.size() > 1) {
		q.pop();
	}
	return q.front();
}

int range(vector<int>& v) {
	return v.back() - v.front();
}
