#include <iostream>
using namespace std;
#include <queue>

void klargest(int arr[],int size,int k){
    priority_queue<int, vector<int>,greater<int>>p;
    for (int i = 0; i < k; i++)
    {
        p.push(arr[i]);
    }
    for (int i = k+1; i < size; i++)
    {
        int temp = p.top();
        if (temp<arr[i])
        {
            p.pop();
            p.push(arr[i]);
        }
        
    }
    int n = p.size(); 
    for (int i = 0; i < n; i++)
    {
        cout<<p.top()<<" ";
        p.pop();
    }
      
}
int main(){
    int arr[13]={2,12,9,16,10,5,3,20,25,11,1,8,6};
    klargest(arr,13,4);
}
