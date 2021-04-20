#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> nums;
	vector<bool> v;
	int T, n;
	cin>>T;
	while(T--){
		int cnt=0;
		vector<int> num_emp;
		vector<bool> v_emp;
		nums.swap(num_emp);
		v.swap(v_emp);
		cin>>n;
		nums.resize(n+1);
		v.resize(n+1, false);
		for(int i=1;i<=n;i++){
			cin>>nums[i];
		}
		for(int i=1;i<=n;i++){
			if(v[i])continue;
			cnt++;
			int next=i;
			do{
				v[next]=true;
				next=nums[next];
			}while(v[next]==false);
		}
		cout<<cnt<<'\n';
	}
	// your code goes here
	return 0;
}
