#include <iostream>
using namespace std;

int coin(int n , int *input , int cd){
    if (n<=0||cd<0)
    {
        return 0;
    }
    if (cd==0)
    {
        return 1;
    }
    
    int a = coin(n,input,cd-input[n-1]);
    int b =coin(n-1,input,cd);

    int ans = a+b;
    return ans;
    
}

int main(){
    int input[3]={1,2,3};
    cout<<coin(3,input,5);
}
