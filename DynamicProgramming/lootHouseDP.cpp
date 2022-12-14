#include <iostream>
using namespace std;
int loot(int n, int*input){
    int *output = new int [n];
    output[0]=input[0];
    output[1]=max(output[0],input[1]);
    for (int i = 2; i < n; i++)
    {
        output[i]=max(output[i-1],output[i-2]+input[i]);
    }
    return output[n-1];
}
int main(){
    int n = 6;
    int arr[6] ={5,5,10,100,10,5}; 
    cout<<loot(n,arr);
}
