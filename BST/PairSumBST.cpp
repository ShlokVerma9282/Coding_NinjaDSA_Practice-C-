#include<iostream>
#include<queue>
#include<stack>
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
        if (head->right==NULL)
        {
             cout<<-1;
        }
        cout<<endl;
    } 
}
void PairSum(BinaryTreeNode<int>*root,int s,int x){
    if (root==0)
    {
        return;
    }
    int count = 0;
    stack<BinaryTreeNode<int>*>min;
    stack<BinaryTreeNode<int>*>max;

    BinaryTreeNode<int>*temp=root;
    while (temp!=NULL)
    {
        min.push(temp);
        temp=temp->left;
    }
    temp=root;
    while (temp!=NULL)
    {
        max.push(temp);
        temp=temp->right;
    }
    while (count<s-1)
    {
        BinaryTreeNode<int>*min_head=min.top();
        BinaryTreeNode<int>*max_head=max.top();

        if (min_head->data+max_head->data==x)
        {
            cout<<min_head->data<<" "<<max_head->data;
            count++;
            BinaryTreeNode<int>*top=min_head;
            min.pop();
            while (top!=NULL)
            {
                top=top->right;
                min.push(top);
            }

            count++;
            BinaryTreeNode<int>*top=max_head;
            max.pop();
            while (top!=NULL)
            {
                top=top->left;
                min.push(top);
            }
        }
        else if (min_head->data+max_head->data>x)
        {
            count++;
            BinaryTreeNode<int>*top=max_head;
            max.pop();
            while (top!=NULL)
            {
                top=top->left;
                min.push(top);
            }
            
        }
        else
        {
            count++;
            BinaryTreeNode<int>*top=min_head;
            min.pop();
            while (top!=NULL)
            {
                top=top->right;
                min.push(top);
            }
            
        }
        
        
    }
    

    


    
}

int main(){
    BinaryTreeNode<int>* root=takeInput();

}