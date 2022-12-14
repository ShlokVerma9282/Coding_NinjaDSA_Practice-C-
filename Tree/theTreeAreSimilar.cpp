#include <iostream>
#include <vector>
#include <queue>
#include "tree.h"
using namespace std;
treeNode<int>*takeInputLevel(){
    int rootData;
    cout<<"Enter the root: "<<endl;
    cin>>rootData;
    treeNode<int>*root= new treeNode<int>(rootData);
    queue<treeNode<int>*>pending_node;
    pending_node.push(root);

    while (pending_node.size()!=0)
    {
        treeNode<int>*front=pending_node.front();
        pending_node.pop();
        int numChild;
        cin>>numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin>>childData;
            treeNode<int>*child=new treeNode<int>(childData);
            front->children.push_back(child);
            pending_node.push(child);
        }
    }
    return root;
}
bool is_sameroot(treeNode<int>*root1,treeNode<int>*root2){
    bool ans = true;
    if (root1->data!=root2->data)
    {
        ans=false;
        return ans;
    }
    
    for(int i=0;i<root1->children.size();i++)
    {
        ans=is_sameroot(root1->children[i],root2->children[i]);
        if (ans==false)
        {
            return ans;
        }
    }
    return ans;

}
int main(){

    treeNode<int>*root1=takeInputLevel();
    treeNode<int>*root2=takeInputLevel();
    bool ans = is_sameroot(root1,root2);
    cout<<ans;
}