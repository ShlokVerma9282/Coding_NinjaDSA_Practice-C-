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
        pending_Node.pop();
        if (head->left!=NULL)
        {
             BinaryTreeNode<int>* Child= head->left;
             head->left=Child;
             cout<<head->left->data<<" ";
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
        if (head->right==NULL)
        {
             cout<<-1;
        }
        cout<<endl;
    } 
}
BinaryTreeNode<int>* BST_copy(BinaryTreeNode<int>*root){
    if (root->left==NULL)
    {
        BinaryTreeNode<int>*copy= new BinaryTreeNode<int>(root->data);
        root->left=copy;
        return root;
    }
    BinaryTreeNode<int>* left = BST_copy(root->left);
    BinaryTreeNode<int>* right = BST_copy(root->right);

    return root;
    
}
int main(){
    BinaryTreeNode<int>*root=takeInput();
    printTree(root);
    BinaryTreeNode<int>*new_root=BST_copy(root);
    cout<<endl;
    cout<<endl;
    printTree(new_root);
    
}