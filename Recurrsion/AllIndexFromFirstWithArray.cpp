#include <iostream>
using namespace std;
void AllIndex(int *arr,int count,int num ){
    static int i = 1;
    static int j =0;
    if (count == 0 && j ==0){
        cout<<"-1";
        return ;
    }
    if (count == 0 && j !=0 )
    {
        return ;
    }
    

    if(arr[0] == num){
        cout<< i<< " ";
        j++;
    }
    i++;
    return AllIndex(arr+1,count-1,num);
    
}
int main(){
    
    int arr[6] = {1,2,4,4,5,6};
    AllIndex(arr,6,4);
    
    
}