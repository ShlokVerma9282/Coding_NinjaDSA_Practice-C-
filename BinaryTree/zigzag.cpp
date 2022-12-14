#include <iostream>
#include <stack>
#include <queue>
#include "BinaryTree.h"
using namespace std;
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Root Data:";
    cin >> rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pending_Node;
    pending_Node.push(root);
    while (pending_Node.size() != 0)
    {
        BinaryTreeNode<int> *head = pending_Node.front();
        pending_Node.pop();
        int leftData;
        cout << "Enter the left child of " << head->data << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *Child = new BinaryTreeNode<int>(leftData);
            head->left = Child;
            pending_Node.push(Child);
        }
        int rightData;
        cout << "Enter the right child of " << head->data << endl;
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
void ZigZag(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;

    s1.push(root);

    while (!s1.empty())
    {

        while (s1.empty() != 1)
        {

            BinaryTreeNode<int> *head = s1.top();
            cout << head->data << " ";
            s1.pop();
            if (head->left != NULL)
            {
                s2.push(head->left);
            }
            if (head->right != NULL)
            {
                s2.push(head->right);
            }
        }
        cout << endl;
        while (!s2.empty())
        {

            BinaryTreeNode<int> *head = s2.top();
            cout << head->data << " ";
            s2.pop();
            if (head->right != NULL)
            {
                s1.push(head->right);
            }
            if (head->left != NULL)
            {
                s1.push(head->left);
            }
        }
        cout<<endl;
    }
}
int main()
{
    BinaryTreeNode<int>*root =takeInput();
    ZigZag(root);
}