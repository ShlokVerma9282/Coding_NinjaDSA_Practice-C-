#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<char> removeDuplicate(char *arr,int size){
    if (size==0)
    {
        vector<char>output;
        output.push_back(-1);
        return output;
    }
    unordered_map<char,bool> check;
    vector<char>output;
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
    char a[7]={'a','b','a','b','a','c','d'};
    vector<char>ans=removeDuplicate(a,7);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i];
    }
    
}
