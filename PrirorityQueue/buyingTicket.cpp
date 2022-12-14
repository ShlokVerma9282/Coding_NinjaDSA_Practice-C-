#include <iostream>
#include<queue>
#include<vector>
using namespace std;
int time(int *arr, int n,int k){
    int count=0;
    priority_queue<int>pq;
    vector<int>prior;
    for (int i = 0; i < n; i++)
    {
        prior.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (!pq.empty())
    {
        if (prior[0]==k&&pq.top()==arr[k])
        {
            count++;
            return count;
        }
        else
        {
            int i =0;
            while (arr[prior[i]]!=pq.top())
            {
            int temp = prior[0];
            vector<int>::iterator it;
            it = prior.begin();
            prior.erase(it);
            prior.push_back(temp);
            }   
            pq.pop();
            vector<int>::iterator it;
            it = prior.begin();
            prior.erase(it);
            count++;
        }
        
        
    }
    return -1;
    
}
int main(){
    int arr[5]={2,3,2,2,4};
    int ans = time(arr,5,3);
    cout<<ans;
}
