#include <iostream>
#include <vector>
using namespace std;


void Set(vector<bool>& tree, int x);
int findPath(vector<bool>& tree, int prv);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<bool> tree;
	int N, Q;
	cin >> N >> Q;
	tree.resize(N + 1, false);
	tree[0] = true;
	//tree True -> 해당 지점으로 들어 갈 수 없음
	while (Q--) 
	{
		int x;
		cin >> x;
		if (tree[x] == false) 
		{
			Set(tree, x);
			cout << "0\n";
		}
		else {
			cout << findPath(tree, x) << '\n';
		}
	}
	return 0;
}
void Set(vector<bool>& tree, int x) {
	if (x >= tree.size()) {
		return;
	}
	if (tree[x]) {
		return;
	}
	tree[x] = true;
	Set(tree, x << 1);
	Set(tree, (x << 1) | 1);
}

int findPath(vector<bool>& tree, int prv) {
	int next = prv >> 1;
	if (next == 0 || tree[next] == false) 
	{
		return prv;
	}
	else {
		return findPath(tree, next);
	}
}
