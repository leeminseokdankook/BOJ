#include <iostream>
using namespace std;

typedef struct _Range {
	int x, y;
	int r;
	bool operator==(struct _Range& a) {
		return (x == a.x) && (y == a.y) && (a.r == r);
	}
}range;

bool IsCircumscription(range& a, range& b);
bool IsInscribed(range& a, range& b);
bool IsSame(range& a, range& b);
bool IsError(range& a, range& b);
int Answer(range& a, range& b);

int main() {
	range a, b;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> a.x >> a.y >> a.r >> b.x >> b.y >> b.r;
		//a의 반지름이 항상 더 작거나 같음
		if (a.r > b.r) {
			swap(a, b);
		}
		cout << Answer(a, b)<<'\n';
	}
	return 0;
}

int Answer(range& a, range& b) {
	if (IsError(a, b)) {
		//어느 점에서도 안 만남
		return 0;
	}
	if (IsSame(a, b)) {
		//무한대
		return -1;
	}
	if (IsCircumscription(a, b) || IsInscribed(a, b)) {
		//내접이나 외접
		return 1;
	}
	return 2;
}

bool IsError(range& a, range& b) {
	//어느 점에서도 만나지 않으면 true
	//큰 원의 중심~작은 원의 중심까지의 거리 + 작은 원의 반지름 <큰 원의 반지름
	int dx, dy, dr1, dr2, center_dis;
	dx = a.x - b.x;
	dy = a.y - b.y;
	center_dis = dx * dx + dy * dy;
	dr1 = b.r - a.r;
	dr2 = b.r + a.r;
	return (center_dis < (dr1* dr1)) || center_dis > (dr2 * dr2);
}

bool IsSame(range& a, range& b) {
	return a == b;
}


bool IsCircumscription(range& a, range& b) {
	//외접
	int dx, dy, dr;
	dx = a.x - b.x;
	dy = a.y - b.y;
	dr = a.r + b.r;
	return (dr * dr) == ((dx * dx) + (dy * dy));
}

bool IsInscribed(range& a, range& b) {
	//내접
	int dx, dy, dr;
	dx = a.x - b.x;
	dy = a.y - b.y;
	dr = b.r - a.r;
	return (dr * dr) == ((dx * dx) + (dy * dy));
}