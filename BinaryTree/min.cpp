#include<iostream>
#include<queue>
#include<algorithm>
#include"BinaryTree.h"
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
int min_binary(BinaryTreeNode<int>*root){
    if (root==NULL)
    {
        return INT16_MAX;
    }
    int ans = root->data;
    int minleft=min_binary(root->left);
    int minRight=min_binary(root->right);
    if (minleft<ans)
    {
        ans=minleft;
    }
    if(minRight<ans){
        ans=minRight;
    }
    return ans;
    
}
int main(){
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* Node1= new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* Node2= new BinaryTreeNode<int>(3);
    BinaryTreeNode<int>* Node11= new BinaryTreeNode<int>(4);
    BinaryTreeNode<int>* Node12= new BinaryTreeNode<int>(5);
    root->left=Node1;
    root->right=Node2;
    Node1->left=Node11;
    Node1->right=Node12;
    printTree(root);
    cout<<min_binary(root);
}