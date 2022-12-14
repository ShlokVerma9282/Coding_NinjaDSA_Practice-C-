#include <iostream>
using namespace std;
int SumOfArray(int *arr,int count,int num ){
    if (count == 0 ){
        return -1;

    }
    if (arr[count-1]==num){
        return count;
    }
    return  SumOfArray(arr, count-1,num);
    

}
int main(){
    
    int arr[6] = {1,2,3,4,5,6};
    cout<<SumOfArray(arr,6,10);
    
}