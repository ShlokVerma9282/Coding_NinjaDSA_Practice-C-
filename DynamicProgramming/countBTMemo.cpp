#include <iostream>
#include<math.h>
using namespace std;

int help(int n, int *ans){
    if (n==0||n==1)
    {
        return 1;
    }
    if (ans[n]!=-1)
    {
        return ans[n];
    }
    int mod = (int)(pow(10,9))+7;
    int x =  help(n-1,ans);
    int y =  help(n-2,ans);

    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)(((long)(y)*x*2)%mod);

    int final = (temp1+temp2)%mod;
    ans[n]=final;

    
    return ans[n];
}


int CountBT(int n){
     int *ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    return help(n, ans);

}
int main(){
    cout<<CountBT(4);    
}
