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

int sumOfAll(treeNode<int>* root){
    int ans=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans+=sumOfAll(root->children[i]);
    }
    return ans;
    
}
treeNode<int>* max_Child(treeNode<int>*root){
    int sum=0;
    int ans=0;
    int j=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans=sumOfAll(root->children[i]);
        if (ans>sum)
        {
            sum=ans;
            j=i;
        }
        
    }
    return root->children[j];
    

}
int main(){

    
    treeNode<int>* root=new treeNode<int>(10);
    treeNode<int>* Node1=new treeNode<int>(20);
    treeNode<int>* Node2=new treeNode<int>(30);
    treeNode<int>* Node11=new treeNode<int>(40);
    treeNode<int>* Node12=new treeNode<int>(50);
    treeNode<int>* Node21=new treeNode<int>(100);

    root->children.push_back(Node1);
    root->children.push_back(Node2);
    Node1->children.push_back(Node11);
    Node1->children.push_back(Node12);
    Node2->children.push_back(Node21);

    root=max_Child(root);
    cout<<root->data;
    
}