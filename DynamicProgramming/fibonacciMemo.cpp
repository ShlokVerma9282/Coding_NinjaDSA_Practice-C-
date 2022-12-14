#include <iostream>
using namespace std;

int helper(int n,int *ans){
    if (n<=1)
    {
        return n;
    }

    if (ans[n]!=-1)
    {
        return ans[n];
    }

    int a = helper(n-1,ans);
    int b = helper(n-2,ans);
    
    ans[n] = a+b;


    return ans[n];
}

int fibo(int n){
    int ans[n+1];
    for (int i = 0; i < n+1; i++)
    {
        ans[i]=-1;
    }
    
    return helper(n,ans);

}
int main(){

    cout<<fibo(6);
    
}
