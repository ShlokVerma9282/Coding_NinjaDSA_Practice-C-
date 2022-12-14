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
treeNode<int>* maxOfAll(treeNode<int>* root){
    treeNode<int>*max = new treeNode<int>(root->data);
    for (int i = 0; i < root->children.size(); i++)
    {
        treeNode<int>* child = maxOfAll(root->children[i]);
        if (child->data>max->data)
        {
            max=child;
        }
         
    }
    return max;
    
}
int main(){

    treeNode<int>*root=takeInputLevel();
    cout<<maxOfAll(root)->data;
    
}