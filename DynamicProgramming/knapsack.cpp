#include <iostream>
using namespace std;
int knap(int n,int *weight,int *value,int maxWeight){
    if (n==0||maxWeight==0)
    {
        return 0;
    }
    if (weight[0]>maxWeight)
    {
        return knap(n-1,weight+1,value+1,maxWeight);
    }
    
    int a = knap(n-1,weight+1,value+1,maxWeight-weight[0])+value[0];
    int b = knap(n-1,weight+1,value+1,maxWeight);

    return max(a,b); 
}
int main(){
    int weight[4]={1,2,4,5};
    int value[4]={5,4,8,6};
    cout<<knap(4,weight,value,5);
    
}
