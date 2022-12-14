#include <iostream>
#include <queue>
#include "BinaryTree.h"
using namespace std;
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

BinaryTreeNode<int>* makeBst(int arr[],int start,int end){

    if (start>end)
    {
        return NULL;
    }
    
    
    int mid = (start+end)/2;
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(arr[mid]);
    root->left=makeBst(arr,start,mid-1);
    root->right=makeBst(arr,mid+1,end);
    return root;
    
}
int main(){
    int arr[7]={1,2,3,4,5,6,7};
    BinaryTreeNode<int>*root = makeBst(arr,0,6);
    printTree(root);
    
}