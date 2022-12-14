#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> removeDuplicate(int *arr,int size){
    if (size==0)
    {
        vector<int>output;
        output.push_back(-1);
        return output;
    }
    unordered_map<int,bool> check;
    vector<int>output;
    for (int i = 0; i < size; i++)
    {
        if (check.count(arr[i])>0)
        {
            continue;
        }
        check[arr[i]]=true;
        output.push_back(arr[i]);
    }
    return output;
}
int main(){
    int a[10]={1,1,1,3,2,4,1,2,3,2};
    vector<int>ans=removeDuplicate(a,10);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}
