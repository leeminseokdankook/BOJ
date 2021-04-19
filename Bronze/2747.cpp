#include<iostream>

int main(){
    int *arr, n;
    std::cin>>n;
    arr=new int[n+1];
    arr[0]=0;arr[1]=1;
    for(int i=2;i<=n;i++) arr[i]=arr[i-1]+arr[i-2];
    std::cout<<arr[n];
    delete[] arr;
    return 0;
}
