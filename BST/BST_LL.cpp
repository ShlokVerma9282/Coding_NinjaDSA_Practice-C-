#include <iostream>
#include <queue>
#include "BinaryTree.h"
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = 0;
    }
};
class Pair
{
public:
    Node *head;
    Node *tail;
};

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
Pair LL(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }

    Node *main = new Node(root->data);

    Pair leftAns = LL(root->left);
    Pair rightAns = LL(root->right);

    Pair ans;

    if (leftAns.head == NULL && rightAns.head == NULL)
    {
        ans.head = main;
        ans.tail = main;
       
    }
        else if (!leftAns.head && rightAns.head)
    {
        ans.head = main;
        main->next = rightAns.head;
        ans.tail = rightAns.tail;
        
    }
    else if (leftAns.head && !rightAns.head)
    {
        ans.head = leftAns.head;
        ans.tail->next = main;
        ans.tail = main;
        
    }
    else
    {
        ans.head = leftAns.head;
        leftAns.tail->next = main;
        main->next = rightAns.head;
        ans.tail = rightAns.tail;
        
    }
    return ans;
}
Node *constructLL(BinaryTreeNode<int> *root)
{
    return LL(root).head;
}
void Print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    Node *head = constructLL(root);
    Print(head);
}