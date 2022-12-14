#include <iostream>
#include <queue>
#include<vector>
#include "tree.h"
using namespace std;
treeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Data: "<<endl;
    cin>>rootData;
    treeNode<int>*root=new treeNode<int>(rootData);
    int n;
    cout<<"Number of data: "<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        treeNode<int>*child=takeInput();
        root->children.push_back(child);
    }
    return root;
    
}
void printTree(treeNode<int>*root){
    if (root==NULL){
        return;
    }
    
    cout<<root->data<<":";
    
    for (int i = 0; i < root->children.size(); i++)
    {
        cout<<root->children[i]->data;
        if (i<root->children.size()-1)
        {
            cout<<",";
        }
        
    }
    cout<<endl;
    
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
    

}
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

    treeNode<int>*root=takeInput();

    printTree(root);
    
}