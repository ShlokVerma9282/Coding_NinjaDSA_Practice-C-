#include <iostream>
using namespace std;
int dup(int arr[],int size){
    
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum+=arr[i];
    }
    int arsum = (size-2)*(size-1)/2;
    return sum-arsum;

}
int main(){
    int i[5]={1,2,3,0,3};
    int size = sizeof(i)/sizeof(i[0]);
    cout<<dup(i,size);
}
