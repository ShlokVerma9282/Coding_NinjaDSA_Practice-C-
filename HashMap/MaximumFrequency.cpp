#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int MaximumFrequency(int *arr,int size){
    if (size==0)
    {
        return -1;
    }
    unordered_map<int,int> check;
    vector<int>output;
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (check.count(arr[i])==0)
        {
            check[arr[i]]=1;
        }
        else
        {
            int temp = check[arr[i]];
            check[arr[i]]=temp+1;
            if (temp+1>max)
            {
                max=temp+1;
            }
            
        }
    }
    return max;
}
int main(){
    int a[10]={1,1,1,3,2,4,1,2,3,2};
    int max =MaximumFrequency(a,10);
    cout<<max;
    
}
