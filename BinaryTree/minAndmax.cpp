#include<iostream>
#include<queue>
#include<algorithm>
#include"BinaryTree.h"
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


pair<int,int> min_Max(BinaryTreeNode<int> *root) {
   if(root->left==NULL && root->right==NULL)
   { pair<int,int> ans;
     ans.second=root->data;
     ans.first=root->data;
      return ans;
   }
   if(root->left!=NULL && root->right==NULL)
   { pair<int,int> ans;
     ans.second=root->data;
     ans.first=root->data;
      return ans;
   }
   if(root->left==NULL && root->right!=NULL)
   { pair<int,int> ans;
     ans.second=root->data;
     ans.first=root->data;
      return ans;
   }
    if (root->left!=NULL)
    {
     pair<int, int> leftAns = min_Max(root->left);
    }

	pair<int,int> rightAns = min_Max(root->right);
    int lmax = leftAns.second;
	int lmin = leftAns.first;
	int rmax = rightAns.second;
	int rmin = rightAns.first;
    
    int max_num = max(lmax,rmax);
    int min_num = min(lmin,rmin);

    pair<int,int> ans;
    ans.second=max_num;
    ans.first=min_num;
    return ans;
    

}
int main(){
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* Node1= new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* Node2= new BinaryTreeNode<int>(0);
    BinaryTreeNode<int>* Node11= new BinaryTreeNode<int>(4);
    BinaryTreeNode<int>* Node12= new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* Node21= new BinaryTreeNode<int>(9);
    root->left=Node1;
    root->right=Node2;
    Node1->left=Node11;
    Node1->right=Node12;
    Node2->left=Node21;
    pair<int,int> ans = min_Max(root);
    cout<<ans.first<<endl;
    cout<<ans.second;
}