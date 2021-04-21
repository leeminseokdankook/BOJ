#include <iostream>
#include <cmath>
using namespace std;

int GetAns(int n){
	return n*5-24;
}
int main() {
	int n,end;
	int val=0;
	cin>>n;
	end=sqrt(n);
	if(n==1){
		cout<<GetAns(n);
	}
	else{
		for(int i=1;i<end;i++){
			if(n%i==0){
				val+=(i+(n/i));
			}
		}
		if(n%end==0){
			if(end*end==n){
                val+=end;
            }
            else{
                val+=(end+(n/end));
            }
		}
		cout<<GetAns(val);
	}
	// your code goes here
	return 0;
}
