#include <iostream>
#include<vector>
using namespace std;

int knap(int n,int *weight,int *value,int maxWeight){
    int **k = new int* [n+1];
    for (int i = 0; i < maxWeight; i++)
    {
        k[i] = new int [maxWeight+1];
    }
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            if (i==0||j==0)
            {
                k[i][j]=0;
            }
            else if (weight[i-1]<=j)
            {
                k[i][j] = max(value[i-1]+k[i-1][j-weight[i-1]],k[i-1][j]);
            }
            else
            {
                k[i][j]=k[i-1][j];
            }
        }
        
    }
    return k[n][maxWeight];
}
int main(){
    int weight[4]={1,2,4,5};
    int value[4]={5,4,8,6};
    cout<<knap(4,weight,value,5);    
}
