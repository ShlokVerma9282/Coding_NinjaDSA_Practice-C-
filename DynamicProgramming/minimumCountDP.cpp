#include <iostream>
#include<math.h>
using namespace std;


int miniCount(int n){
    if (sqrt(n)-floor(sqrt(n))==0)
        {
            return 1;
        }
    int *ans = new int[n + 1];
    ans[0]=0;
    ans[1]=1;
    ans[2]=2;
    ans[3]=3;

    for (int i = 4; i <=n; i++)
    {
        ans[i] = i;

        for (int x = 1; x <=floor(sqrt(i)); x++)
        {
            int temp = x*x;
            if (temp>i)
            {
                break;
            }
            else{
            ans[i]=min(ans[i],1+ans[i-temp]);
            }
        }
        
    }
    return ans[n];
}
int main(){
    cout<<miniCount(5);    
}
