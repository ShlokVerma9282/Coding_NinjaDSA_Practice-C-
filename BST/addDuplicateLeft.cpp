#include <iostream>
#include <queue>
using namespace std;
template<typename T>
class BinaryTreeNode
{
public:
T data;
BinaryTreeNode* left;
BinaryTreeNode* right;
BinaryTreeNode(T data){
    this->data=data;
    left=NULL;
    right=NULL;
}
~BinaryTreeNode(){
    delete left;
    delete right;
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
void BST_copy(BinaryTreeNode<int>*root){
    if (root==NULL)
    {
        return;
    }
    BinaryTreeNode<int>* Duplicate = new BinaryTreeNode<int>(root->data);
    if (root->right!=NULL)
    {
    BinaryTreeNode<int>* DuplicateRight = root->right;
    Duplicate->right=DuplicateRight;
    } 
    Duplicate->left=root->left;
    root->left=Duplicate;
    BST_copy(Duplicate->left);
    if (root->right!=NULL)
    {
        if (root->right->left!=NULL)
        {
            BST_copy(root->right);
        }
    }
    
    
    


    
}
int main(){
    BinaryTreeNode<int>*root=takeInput();
    printTree(root);
    BST_copy(root);
    cout<<endl;
    cout<<endl;
    printTree(root);
    
}