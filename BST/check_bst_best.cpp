#include <iostream>
#include <queue>
#include "BinaryTree.h"
using namespace std;

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Root Data:"<<endl;
    cin>>rootData;
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pending_Node;
    pending_Node.push(root);
    while (pending_Node.size()!=0)
    {
        BinaryTreeNode<int>* head= pending_Node.front();
        pending_Node.pop();
        int leftData;
        cin>>leftData;
        if (leftData!=-1)
        {
             BinaryTreeNode<int>* Child= new BinaryTreeNode<int>(leftData);
             head->left=Child;
             pending_Node.push(Child);
        }
        int rightData;
        cin>>rightData;
        if (rightData!=-1)
        {
             BinaryTreeNode<int>* Child= new BinaryTreeNode<int>(rightData);
             head->right=Child;
             pending_Node.push(Child);
        }
        
    }
    return root;
}
void printTree(BinaryTreeNode<int>*root){
    if (root==NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*>pending_Node;
    pending_Node.push(root);
    while (pending_Node.size()!=0)
    {
        BinaryTreeNode<int>* head= pending_Node.front();
        cout<<head->data<<":";
        pending_Node.pop();
        if (head->left!=NULL)
        {
             BinaryTreeNode<int>* Child= head->left;
             head->left=Child;
             cout<<head->left->data<<",";
             pending_Node.push(Child);
        }
        if (head->left==NULL)
        {
             cout<<-1<<",";
        }
        if (head->right!=NULL)
        {
             BinaryTreeNode<int>* Child= head->right;
             head->right=Child;
             cout<<head->right->data;
             pending_Node.push(Child);
        }
        if (head->left==NULL)
        {
             cout<<-1;
        }
        cout<<endl;
    } 
}
int maximum(BinaryTreeNode<int>*root){
    if (root==NULL)
    {
        return INT16_MIN;
    }
    return max(root->data,max(maximum(root->left),maximum(root->right)));
    
}
int minimum(BinaryTreeNode<int>*root){
    if (root==NULL)
    {
        return INT16_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
    
}
bool check_BST(BinaryTreeNode<int>*root,int max=INT16_MIN,int min=INT16_MAX){
    if ( root==NULL ){  
        return true;  
    }
    if (root->data<min && root->data>max)
    {
        return false;
    }

    bool is_left_ok=check_BST(root->left,min,root->data-1);
    bool is_right_ok=check_BST(root->right,root->data,max);

    return is_left_ok&&is_right_ok;
     
}
int main(){
    BinaryTreeNode<int>*root=takeInput();
    printTree(root);
    bool ans=check_BST(root);
    if (ans)
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
    
}