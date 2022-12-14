#include<iostream>
#include<queue>
#include"BinaryTree.h"
using namespace std;

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Root Data:";
    cin>>rootData;
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pending_Node;
    pending_Node.push(root);
    while (pending_Node.size()!=0)
    {
        BinaryTreeNode<int>* head= pending_Node.front();
        pending_Node.pop();
        int leftData;
        cout<<"Enter the left child of "<<head->data<<endl;
        cin>>leftData;
        if (leftData!=-1)
        {
             BinaryTreeNode<int>* Child= new BinaryTreeNode<int>(leftData);
             head->left=Child;
             pending_Node.push(Child);
        }
        int rightData;
        cout<<"Enter the right child of "<<head->data<<endl;
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
    cout<<root->data<<":";
    if (root->left!=NULL)
    {
        cout<<"L"<<root->left->data<<",";
    }
    if (root->left==NULL)
    {
        cout<<"Null,";
    }
    if (root->right!=NULL)
    {
        cout<<"R"<<root->right->data;
    }
    if (root->right==NULL)
    {
        cout<<"Null";
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
    
}
int main(){
    BinaryTreeNode<int>* root=takeInput();
    printTree(root);
}