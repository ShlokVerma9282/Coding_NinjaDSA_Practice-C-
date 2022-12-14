#include <iostream>
using namespace std;

int tower(int n,int x,int y){
    int output[n+1];
    output[0]=false;
    output[1]=true;

    for (int i = 0; i <=n; i++)
    {
        if (i-y>=0 and !output[i-y])
        {
            output[i]=true;
        }
        else if (i-x>=0 and !output[i-x])
        {
            output[i]=true;
        }
        else if (i-1>=0 and !output[i-1])
        {
            output[i]=true;
        }
        else
        {
            output[i]=false;
        }
    }
    return output[n];
    
}
int main(){
    cout<<tower(4,2,3);
}
