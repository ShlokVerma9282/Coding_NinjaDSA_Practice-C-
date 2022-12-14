#include<iostream>
#include<queue>
#include<vector>
#include"BinaryTree.h"
using namespace std;
class Node
{
public:
int data;
Node *next;

Node(int data){
    this->data=data;
    next=0;
}


};
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
vector<Node*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    
    vector<Node*> v;
    
	if(root==NULL)
    {
       v.push_back(NULL) ;
        
        return v;
    }
        
    
    queue<BinaryTreeNode<int> *> pn;
    
    pn.push(root);
    pn.push(NULL);
    
    Node *head=NULL;
    Node  *tail =head;
    
   
    while(pn.size()!=0)
    { 
        BinaryTreeNode<int> *front=pn.front();
        pn.pop();
        
       if(front==NULL)
       { tail->next=NULL;
        
        if(pn.size()==0)
           break;
        
        pn.push(NULL);
        
        head=NULL;
        tail=NULL;
       }
        
     else
     {  
       Node *n=new node<int> (front->data);
       if(head==NULL)
       {
           head=tail=n;
           v.push_back(head);
       }
      else
      {
          tail->next=n;
          tail=n;
      }
     
        if(front->left)
        pn.push(front->left);
        if(front->right)
         pn.push(front->right);
     }
    }
}
int main(){
    BinaryTreeNode<int>* root=takeInput();

}