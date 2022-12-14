#include <iostream>
using namespace std;
void Sum(int arr[],int size,int j,int target){
    if(arr[j]=='\0'){
        return;
    }
    for (int k = j; k < size-1; k++)
    {
        if(arr[j]+arr[k]==target){

            cout<<j+1<<" "<<k+1<<endl;

        }
    }
    return Sum(arr,size,j+1,target);

}
int main(){
    int i[9]={5,12,3,17,1,18,15,3,17};
    int size = sizeof(i)/sizeof(i[0]);
    Sum(i,size,0,6);

}
