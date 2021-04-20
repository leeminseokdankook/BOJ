#include <iostream>
using namespace std;

int main(){
    int T,N,count[42]={1,0};
    for(int i=2;i<=41;i++){
        count[i]=count[i-1]+count[i-2];
    }
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        printf("%d %d\n", count[N], count[N+1]);
    }
    return 0;
}