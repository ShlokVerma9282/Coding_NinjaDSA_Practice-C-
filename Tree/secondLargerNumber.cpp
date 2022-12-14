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
void helper(treeNode<int>*root,treeNode<int>**first,treeNode<int>**second){
    if (!(*first))
    {
        *first=root;
    }
    else if(root->data>(*first)->data){
        *second=*first;
        *first=root;
    }
    else if (!(second)||root->data>(*second)->data)
    {
        *second=root;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        helper(root->children[i],first,second);
    }
}
treeNode<int>*second(treeNode<int>*root){
    treeNode<int>*first=NULL;
    treeNode<int>*second=NULL;
    helper(root,&first,&second);
    if (second==NULL)
    {
        return NULL;
    }
    else if (first->data==second->data)
    {
        return NULL;
    }
    return second;
    
}
int main(){

    treeNode<int>*root=takeInputLevel();
    cout<<second(root)->data;
    
}