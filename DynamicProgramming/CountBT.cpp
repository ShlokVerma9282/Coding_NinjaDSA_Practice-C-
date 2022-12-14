#include <iostream>
#include<math.h>
using namespace std;
int countBT(int n){
    if (n<=1)
    {
        return 1;
    }

    int mod = (int)(pow(10,9))+7;
    int x = countBT(n-1);
    int y = countBT(n-2);

    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)(((long)(y)*x*2)%mod);

    int ans = (temp1+temp2)%mod;

    return ans;
    
}
int main(){
    cout<<countBT(4);    
}
