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

class Pair{
    public:
    int minimum;
    int maximum;
    bool is_bst;
    int height;
};

Pair LargestBST(BinaryTreeNode<int>*root){
    if (root==NULL)
    {
        Pair ans;
        ans.minimum=INT16_MAX;
        ans.maximum=INT16_MIN;
        ans.is_bst=true;
        ans.height=0;
        return ans;
    }

    Pair left=LargestBST(root->left);
    Pair right=LargestBST(root->right);


    int minimum=min(root->data,min(left.minimum,right.minimum));
    int maximum=max(root->data,max(left.maximum,right.minimum));
    bool is_bst=(root->data>left.maximum)&&(root->data<right.minimum)&&left.is_bst&&right.is_bst;

    Pair ans;
    ans.minimum=minimum;
    ans.maximum=maximum;
    ans.is_bst=is_bst;
    if (is_bst)
    {
        ans.height= 1+ max(left.height,right.height);
    }
    else{
        ans.height=max(left.height,right.height);
    }
    return ans;
    
}

    
    
int main(){
    BinaryTreeNode<int>*root=takeInput();
    printTree(root);
    cout<<endl;
    cout<<endl;
    cout<<LargestBST(root).height;
   
}