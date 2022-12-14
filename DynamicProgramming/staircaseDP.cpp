#include <iostream>
using namespace std;
int stair(int n){
    int *ans = new int [n+1];
    ans[0]=1;
    ans[1]=1;
    ans[2]=2;

    for (int i = 3; i < n+1; i++)
    {
        ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
    }
    return ans[n];
}
int main(){
    cout<<stair(10);    
}
