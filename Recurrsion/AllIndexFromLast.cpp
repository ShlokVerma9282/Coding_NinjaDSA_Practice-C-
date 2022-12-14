#include <iostream>
using namespace std;
void SumOfArray(int *arr,int count,int num ){
    if (arr[count-1]==num){
        cout << count<<" ";
    }
    count--;
      if (count == 0 ){
        return ;
    }
    return  SumOfArray(arr, count,num);

}
int main(){
    
    int arr[6] = {1,2,1,4,5,6};
    SumOfArray(arr,6,1);
    
}