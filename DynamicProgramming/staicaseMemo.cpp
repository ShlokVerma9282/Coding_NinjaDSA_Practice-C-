#include <iostream>
using namespace std;

int help(int n ,int*ans){
    if (n<=1)
    {
        return 1;
    }
    if (n==2)
    {
        return 2;
    }

    
       
    if (ans[n]!=-1)
    {
        return ans[n];
    }
    int x=help(n-1,ans);
    int y=help(n-2,ans);
    int z=help(n-3,ans);

    ans[n]=(x+y+z);

    return ans[n];
    
}



int stair(int n){
    int *ans = new int [n+1];
    for (int i = 0; i < n+1; i++)
    {
        ans[i]=-1;
    }
    
    return help(n,ans);
}
int main(){

    cout<<stair(4);
    
}
