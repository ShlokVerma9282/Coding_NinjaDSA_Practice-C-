#include <iostream>
using namespace std;

int loot(int n , int *input){
    if (n<=0)
    {
        return 0;
    }
    int a = loot(n-2,input+2)+input[0];
    int b = loot(n-1,input+1);

    return max(a,b);

}
int main(){

    int n = 6;
    int arr[6] ={5,5,10,100,10,5}; 
    cout<<loot(n,arr);
    
}
