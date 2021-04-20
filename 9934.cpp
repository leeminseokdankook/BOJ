#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k,cnt;
	vector<int> node;
	vector<list<int>> tree;
	cin>>k;
	cnt=1<<k;
	node.resize(cnt);
	tree.resize(k,list<int>());
	for(int i=1;i<cnt;i++){
		cin>>node[i];
	}
	
	for(int floor=1;floor<=k;floor++){
		int start_index=1<<(floor-1);
		int next=1<<floor;
		int tree_index=k-floor;
		for(int index=start_index;index<cnt;index+=next){
			tree[k-floor].push_back(node[index]);
		}
	}
	for(int i=0;i<k;i++){
		auto end=tree[i].end();
		for(auto iter=tree[i].begin();iter!=end;iter++){
			cout<<*iter<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
