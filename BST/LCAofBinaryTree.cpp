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
        if (head->right==NULL)
        {
             cout<<-1;
        }
        cout<<endl;
    } 
}

bool search(BinaryTreeNode<int>*root,int x){
    bool ans=false;
    if (root->data==x)
    {
        ans = true;
        root->data=INT16_MIN;
        return ans;
    }
    if (root->left!=NULL)
    {
        bool leftans = search(root->left,x);
        if (leftans)
        {
            ans=leftans;
        }
    }
    if (root->right!=NULL)
    {
        bool rightans = search(root->right,x);
        if (rightans)
        {
            ans=rightans;
        }
    }
    return ans;
  
}
int LCA(BinaryTreeNode<int>*root,int x,int y){
    if (root==NULL)
    {
        return -1;
    }
    if ((root->data==x||root->data==y))
    {
        return root->data;
    }

    int lnode = LCA(root->left,x,y);
    int rnode = LCA(root->right,x,y);

    if (lnode==-1 and rnode==-1)
    {
        return -1;
    }
    else if (lnode!=-1 and rnode==-1)
    {
        return lnode;
    }
    else if (lnode==-1 and rnode!=-1)
    {
        return rnode;
    }
    else{
        return root->data;
    }
    
    
    
}
int main(){
    BinaryTreeNode<int>*root=takeInput();
    printTree(root);
    cout<<endl;
    cout<<endl;
    cout<<LCA(root,6,9);
    
}