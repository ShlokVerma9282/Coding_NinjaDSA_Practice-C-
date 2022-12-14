#include <iostream>
#include <vector>
#include <queue>
#include "tree.h"
using namespace std;
treeNode<int>*takeInputLevel(){
    int rootData;
    cout<<"Enter the root: "<<endl;
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
void deapthK(treeNode<int>*root,int k){
    if (k==0)
    {
        cout<<root->data<<endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        deapthK(root->children[i],k-1);
    }
    
}
int main(){

    treeNode<int>*root=takeInputLevel();

    deapthK(root,1);
    
}