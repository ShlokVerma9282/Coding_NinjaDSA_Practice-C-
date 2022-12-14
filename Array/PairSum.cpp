#include <iostream>
#include<algorithm>
using namespace std;
void pair_sum(int arr[],int i,int j,int target,int count){
    if (i>j)
    {
        cout<<count<<endl;
        return;
    }
    if (arr[i]+arr[j]==target)
    {
        cout<<i<<" "<<j<<endl;
        count++;
        if(arr[i]==arr[i+1]){
        pair_sum(arr,i+1,j,target,count);
        }
        if(arr[j]==arr[j-1]){
        pair_sum(arr,i,j-1,target,count);
        }
        else{
            pair_sum(arr,i,j-1,target,count);
        }
    }
     if (arr[i]+arr[j]<target)
    {
        pair_sum(arr,i+1,j,target,count);
    }
     if (arr[i]+arr[j]>target)
    {
        pair_sum(arr,i,j-1,target,count);
    }  

}
int main(){
    int i[9]={1,3,6,2,5,4,3,2,4};
    int size = sizeof(i)/sizeof(i[0]);
    sort(i,i+size);
    pair_sum(i,0,size-1,7,0);


}