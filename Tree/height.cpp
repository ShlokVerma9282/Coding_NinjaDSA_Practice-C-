#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "tree.h"
using namespace std;
treeNode<int>*takeInputLevel(){
    int rootData;
    cout<<"Enter the root: ";
    cin>>rootData;
    treeNode<int>*root= new treeNode<int>(rootData);
    queue<treeNode<int>*>pending_node;
    pending_node.push(root);

    while (pending_node.size()!=0)
    {
        treeNode<int>*front=pending_node.front();
        pending_node.pop();
        int numChild;
        cout<<"Enter Number of Children:";
        cin>>numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout<<"Enter the Child Data: ";
            cin>>childData;
            treeNode<int>*child=new treeNode<int>(childData);
            front->children.push_back(child);
            pending_node.push(child);
        }
    }
    return root;
}
int height(treeNode<int>*root){
    int h=1;
    if(root->children.size()==0)
        return h;
    int arr[root->children.size()];
    for (int i = 0; i < root->children.size(); i++)
    {
        arr[i]=height(root->children[i]);
    }
    sort(arr,arr+root->children.size(),greater<int>());
         h+=arr[0];
    return h;
}
int main(){

    treeNode<int>*root=takeInputLevel();

    cout<<height(root);
    
}