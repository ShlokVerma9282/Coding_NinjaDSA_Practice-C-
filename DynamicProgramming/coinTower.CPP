#include <iostream>
using namespace std;

int help(int n,int x,int y,int *dp){
    if (n<0)
    {
        return INT16_MAX;
    }
    if (n==0)
    {
        return 0;
    }
    if (dp[n-1]!=-1)
    {
        return dp[n-1];
    }
    
    int ans;
    int a = help(n-1,x,y,dp);
    int b = help(n-x,x,y,dp);
    int c = help(n-y,x,y,dp);
    ans = min(a,min(b,c));
    if (ans==0)
    {   
        dp[n-1] = 1;
    }
    if (ans!=0)
    {
        dp[n-1]=0;
    }
    return dp[n-1];
}
int tower(int n,int x,int y ){
    int *output = new int[n];
    for (int i = 0; i < n; i++)
    {
        output[i]=-1;
    }
    
    return help(n,x,y,output);

}
int main(){
    cout<<tower(4,2,3);
    
}
