#include<iostream>
#include<queue>
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
void printNodeDownK(BinaryTreeNode<int>*root,int k){
    if (root==NULL||k<0)
    {
        return;
    }
    if (k==0)
    {
        cout<<root->data<<endl;
        return;
    }
    printNodeDownK(root->left,k-1);
    printNodeDownK(root->right,k-1);
}

int intkdistanceNode(BinaryTreeNode<int>*root,int target,int k){
    if (root==NULL)
    {
        return -1;
    }
    if (root->data==target)
    {
        printNodeDownK(root,k);
        return 0;
    }
    int dl = intkdistanceNode(root->left,target,k);
    if (dl!=-1)
    {
        if (dl+1==k)
        {
            cout<<root->data<<endl;
        }
        else
        {
            printNodeDownK(root->right,k-(dl+2));
        }
        return 1+dl;
    }
    int dr = intkdistanceNode(root->left,target,k);
    if (dr!=-1)
    {
        if (dr+1==k)
        {
            cout<<root->data<<endl;
        }
        else
        {
            printNodeDownK(root->left,k-(dr+2));
        }
        return 1+dr;
    }
    return -1;
    
}

int main(){
    BinaryTreeNode<int>* root=takeInput();
    int ans =intkdistanceNode(root,3,1);
}