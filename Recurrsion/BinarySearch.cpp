#include <iostream>
using namespace std;
int binarysearch(int arr[],int start,int end,int target){
    if (end>=start)
    {
        auto mid = start +(end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        if (target >arr[mid])
        {
            binarysearch(arr,mid+1,end,target);
        }
        else
        {
            binarysearch(arr,start,mid-1,target);
        }
    }
    return -1;
}
int main(){
    int arr[6]={1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<binarysearch(arr,0,size,4);
}
