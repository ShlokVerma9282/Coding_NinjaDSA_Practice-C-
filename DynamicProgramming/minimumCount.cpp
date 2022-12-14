#include <iostream>
#include<math.h>
using namespace std;

int minCount(int n){
    if (sqrt(n)-floor(sqrt(n))==0)
    {
        return 1;
    }
    if (n<=3)
    {
        return n;
    }
    int res = n;
    for (int i = 1; i < n; i++)
    {
        int temp = pow(i,2);
        if (temp>n)
        {
           break;
        }
        else{
            res = min(res,1+minCount(n-temp));
        }
        
    }
    return res;

}
int main(){
    cout<<minCount(5);    
}
