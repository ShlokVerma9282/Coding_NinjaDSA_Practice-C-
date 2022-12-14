#include <iostream>
#include <queue>
#include<vector>
#include "BinaryTree.h"
using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Root Data:" << endl;
    cin >> rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pending_Node;
    pending_Node.push(root);
    while (pending_Node.size() != 0)
    {
        BinaryTreeNode<int> *head = pending_Node.front();
        pending_Node.pop();
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *Child = new BinaryTreeNode<int>(leftData);
            head->left = Child;
            pending_Node.push(Child);
        }
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *Child = new BinaryTreeNode<int>(rightData);
            head->right = Child;
            pending_Node.push(Child);
        }
    }
    return root;
}
void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pending_Node;
    pending_Node.push(root);
    while (pending_Node.size() != 0)
    {
        BinaryTreeNode<int> *head = pending_Node.front();
        cout << head->data << ":";
        pending_Node.pop();
        if (head->left != NULL)
        {
            BinaryTreeNode<int> *Child = head->left;
            head->left = Child;
            cout << head->left->data << ",";
            pending_Node.push(Child);
        }
        if (head->left == NULL)
        {
            cout << -1 << ",";
        }
        if (head->right != NULL)
        {
            BinaryTreeNode<int> *Child = head->right;
            head->right = Child;
            cout << head->right->data;
            pending_Node.push(Child);
        }
        if (head->left == NULL)
        {
            cout << -1;
        }
        cout << endl;
    }
}
vector<int>* rootPath(BinaryTreeNode<int>*root,int x){
    if (root==NULL)
    {
        return NULL;
    }
    
    if (root->data==x)
    {
        vector<int>* ans = new vector<int>();
        ans->push_back(root->data);
        return ans;
    }
    vector<int>* leftans=rootPath(root->left,x);
    if (root->left!=NULL)
    {
        leftans->push_back(root->data);
        return leftans;
    }
    vector<int>* rightans=rootPath(root->right,x);
    if (root->right!=NULL)
    {
        rightans->push_back(root->data);
        return rightans;
    }
    else
    {
        return NULL;
    }    
    
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    

}