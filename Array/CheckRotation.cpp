#include <iostream>
using namespace std;
int search(int arr[],int start,int end){

    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]<arr[mid-1]||arr[mid]>arr[mid+1]){
            if(arr[mid+2]<arr[mid]&&arr[mid]>arr[mid>1]){
              return mid+1;
              }
            if(arr[mid-2]>arr[mid]&&arr[mid]>arr[mid-1]){
              return mid-1;
              }
            return mid;
            
        }
        if (arr[start]<arr[mid])
        {
            if (arr[mid-1]<arr[mid])
            {
                start = mid;
            }
            else{
                end =mid;
            }
            
        }
            if (arr[start]>arr[mid])
        {
            if (arr[mid+1]>arr[mid])
            {
                end = mid;
            }
            else{
                start =mid-1;
            }
            
        }
    }
    return -1;
}
int main(){
    int i[9]={4,5,6,7,8,9,1,2,3};
    int size = sizeof(i)/sizeof(i[0]);
    cout<<search(i,0,size-1);

}