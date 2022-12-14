#include <iostream>
using namespace std;

int help(int n , int *input,int *output){
    if (n<=0)
    {
        return 0;
    }
    int a = help(n-2,input+2,output)+input[0];
    int b = help(n-1,input+1,output);

    int ans =  max(a,b);
    output[n] = ans;
    return ans;

}
int loot(int n,int*input){
    int *output = new int [n];
    for (int i = 0; i < n; i++)
    {
        output[i] = -1;
    }
    return help(n,input,output);

}
int main(){

    int n = 6;
    int arr[6] ={5,5,10,100,10,5}; 
    cout<<loot(n,arr);
    
}