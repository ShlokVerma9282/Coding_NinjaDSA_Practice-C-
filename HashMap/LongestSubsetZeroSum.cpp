#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void Long(int *arr,int size){
    int max = 0;
    int sum = 0;
    unordered_map<int,int> check;
    for (int i = 0; i < size; i++)
    {
        sum+=arr[i];
        if (check.count(sum)>0)
        {
            int tempMAX=i-check[sum];
            if (tempMAX>max)
            {
                max=tempMAX;
            }
        }
        else
        {
            check[sum]=i;
        }
    }
    cout<<max;  
}
int main(){
    int a[10]={95,-97,-387,-435,-5,-70,897,127,23,284};
    Long(a,10);
}
