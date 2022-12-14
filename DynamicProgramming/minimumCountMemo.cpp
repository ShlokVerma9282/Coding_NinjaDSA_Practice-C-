#include <iostream>
#include<math.h>
using namespace std;

int help(int n, int *ans){
    if (sqrt(n)-floor(sqrt(n))==0)
    {
        ans[n]=1;
        return ans[n];
    }
    if (n<=3)
    {
        ans[n]=n;
        return ans[n];
    }
    int res = n;  
    if (ans[n]!=-1)
    {
        return ans[n];
    }  
    for (int i = 1; i <=n; i++)
    {
        int temp = i*i;
        if (temp>n)
        {
            break;
        }
        else
        {
            res=min(res,1+help(n-temp,ans));
            ans[n]=res;

        }
    }
    return ans[n];
}


int miniCount(int n){
     int *ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    return help(n, ans);

}
int main(){
    cout<<miniCount(5);    
}
