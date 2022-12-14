#include <bits/stdc++.h> 
#include <iostream>
#include<algorithm>
using namespace std;

void rotate_arr(int*&arr,int target,int size){
    reverse(arr,arr+size);
    reverse(arr,arr+(size-target));
    reverse(arr+(size-target),arr+size);
}
int main() {
    //Write your code here
    int n;
    cin>>n;
    int *arr = new int(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    rotate_arr(arr,m,n);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}