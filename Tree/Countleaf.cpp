#include <iostream>
#include <vector>
#include <queue>
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
        cin>>numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin>>childData;
            treeNode<int>*child=new treeNode<int>(childData);
            front->children.push_back(child);
            pending_node.push(child);
        }
    }
    return root;
}
int countLeaf(treeNode<int>*root){
    int count=0;
    if (root->children.size()==0)
    {
        count++;
        return count;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count+=countLeaf(root->children[i]);
    }
    return count;
    
}
int main(){

    treeNode<int>*root=takeInputLevel();

    cout<<countLeaf(root);
    
}