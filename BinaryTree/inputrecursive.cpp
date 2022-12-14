#include <iostream>
#include "BinaryTree.h"
using namespace std;
BinaryTreeNode<int>* inputData(BinaryTreeNode<int>*root){
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    if (rootData==-1)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = intputData();
    BinaryTreeNode<int>* rightChild = intputData();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}

int main(){
    
}