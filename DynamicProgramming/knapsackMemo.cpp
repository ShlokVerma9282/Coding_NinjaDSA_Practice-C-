#include <iostream>
using namespace std;
int help(int n,int *weight,int *value,int maxWeight,int**output){
    if (n==0||maxWeight==0)
    {
        return 0;
    }
    if (output[n-1][n-1]!=-1)
    {
        return output[n-1][n-1];
    }
    
    if (weight[0]>maxWeight)
    {
        return help(n-1,weight+1,value+1,maxWeight,output);
    }
    
    int a = help(n-1,weight+1,value+1,maxWeight-weight[0],output)+value[0];
    int b = help(n-1,weight+1,value+1,maxWeight,output);

    int ans =  max(a,b);
    output[n-1][n-1]=ans;
    return ans;
}
int knap(int n,int *weight,int *value,int maxWeight){
    int **output = new int*[n];
    for (int i = 0; i <n; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j <n; j++)
        {
            output[i][j]=-1;
        }
        
    }
    return help(n,weight,value,maxWeight,output);

}
int main(){
    int weight[4]={1,2,4,5};
    int value[4]={5,4,8,6};
    cout<<knap(4,weight,value,5);
    
}
