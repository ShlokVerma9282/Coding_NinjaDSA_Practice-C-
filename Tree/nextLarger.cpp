#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class treeNode{
public:
T data;
vector<treeNode<T>*>children;
treeNode(T data){
    this->data=data;
}
~treeNode(){
    for (int i = 0; i < children.size(); i++)
    {
        delete children[i];
    }
    
}

};
treeNode<int>* nextLarger(treeNode<int>* root,int n){
    treeNode<int>*max = NULL;
    if (root->data>n)
    {
        max=root;
    }
    
    for (int i = 0; i < root->children.size(); i++)
    {
        treeNode<int>* child = nextLarger(root->children[i],n);
        if (max==NULL)
        {
            max=child;
        }
        else if(child->data>n && max->data>child->data){
            max=child;
        }
   
    }
    return max;
    
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
    cout<<nextLarger(root,50)->data;
    
}