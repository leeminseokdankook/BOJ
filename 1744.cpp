#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	vector<int> vals;
	int answer=0;
	int N;
	cin>>N;
	vals.resize(N);
	int left=0;
	int right=N-1;
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		vals[i]=x;
	}
	sort(vals.begin(), vals.end());
	//음수 묶기
	for(left=0;left<right;left+=2){
		if(vals[left]<1&&vals[left+1]<1){
			answer+=vals[left]*vals[left+1];
		}
		else{
			break;
		}
	}
	
	//양수묶기
	
	while(right>0){
		if(vals[right]>1&&vals[right-1]>1){
			answer+=vals[right]*vals[right-1];
		}
		else{
			break;
		}
		right-=2;
	}
	
	while(left<=right){
		answer+=vals[left];
		left++;
	}
	
	cout<<answer;
	return 0;
}
