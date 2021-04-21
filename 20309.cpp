#include <vector>
#include <iostream>
using namespace std;

int main(){
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int val;
        cin>>val;
        if((i&1)!=(val&1)){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
