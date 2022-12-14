#include <iostream>
#include <queue>
#include "tree.h"
using namespace std;



bool containX(treeNode<int>* root,int x){
    bool ans = false;
    if (root->data==x)
    {
        ans = true;
        return ans;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        ans=containX(root->children[i],x);
        if (ans==true)
        {
            return ans;
        }
        
    }
    return ans;
}
int main(){
    treeNode<int>* root=new treeNode<int>(10);
    treeNode<int>* Node1=new treeNode<int>(20);
    treeNode<int>* Node2=new treeNode<int>(30);
    treeNode<int>* Node11=new treeNode<int>(40);
    treeNode<int>* Node12=new treeNode<int>(50);
    treeNode<int>* Node21=new treeNode<int>(60);

    root->children.push_back(Node1);
    root->children.push_back(Node2);
    Node1->children.push_back(Node11);
    Node1->children.push_back(Node12);
    Node2->children.push_back(Node21);

    int x =20;
    bool ans =containX(root,x);
    if (ans==1)
    {
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    
    
}