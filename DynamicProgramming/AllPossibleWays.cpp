#include <iostream>
#include<math.h>
using namespace std;

int check(int x,int n,int curr_num,int curr_sum){
    int res=0;
    int p = pow(curr_num,n);
    while(p+curr_sum<x){
        res += check(x,n,curr_num+1,curr_sum+p);
        curr_num++;
        p=pow(curr_num,n);
    }
    if(p+curr_sum==x)
        res++;
    return res;
}

int allWays(int x, int n) {
    return check(x,n,1,0);
}
int main(){
    cout<<allWays(10,2);
}
