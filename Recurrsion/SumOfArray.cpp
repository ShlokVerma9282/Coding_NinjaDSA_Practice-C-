#include <iostream>
using namespace std;
int SumOfArray(int *arr,int count){
    if (count == 0 ){
        return 0;

    }
    return arr[count-1] + SumOfArray(arr, count-1);

}
int main(){
    
    int arr[6] = {1,2,3,4,5,6};
    cout<<SumOfArray(arr,6);
    
}