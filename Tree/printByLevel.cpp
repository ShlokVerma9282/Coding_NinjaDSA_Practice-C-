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
void PrintbyLevel(treeNode<int>*root){
    if (root==NULL)
    {
        return;
    }
    queue<treeNode<int>*>pending_node;
    pending_node.push(root);
    while (pending_node.size()!=0)
    {
        treeNode<int>*head=pending_node.front();
        pending_node.pop();
        cout<<head->data<<":";
        for (int i = 0; i <head->children.size(); i++)
        {
           pending_node.push(head->children[i]); 
           if (i!=head->children.size()-1)
           {
            cout<<head->children[i]->data<<",";
           }
           else{
            cout<<head->children[i]->data;
           }
        }
        cout<<endl;
        
    }
    


}
int main(){

    treeNode<int>*root=takeInputLevel();

    PrintbyLevel(root);
    
}