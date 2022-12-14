#include<iostream>
#include<queue>
#include<vector>
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
void printV(vector <int> const a) {

   for(int i=0; i < a.size(); i++)
   cout << a.at(i) << ' ';
}
void path(BinaryTreeNode<int>*root,int k,vector<int> s){
    if(root==NULL){
        return;
    }
    if (k-(root->data)==0&&root->left==NULL&&root->right==NULL)
    {
        s.push_back(root->data);
        printV(s);
        cout<<endl;
        return;
    }
    else if(k-(root->data)>0)
    {
        s.push_back(root->data);
    }
    else
    {
        return;
    }
    path(root->left,k-(root->data),s);
    path(root->right,k-(root->data),s);

}
int main(){
    BinaryTreeNode<int>* root=takeInput();
    printTree(root);
    cout<<endl;
    vector<int> s;
    path(root,13,s);

}