#include <iostream>
#include <queue>
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
class check_bst_return
{
public:
    bool check_bst;
    int maximum;
    int minimum;
    check_bst_return is_bst(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            check_bst_return output;
            output.maximum = INT16_MIN;
            output.minimum = INT16_MAX;
            output.check_bst = true;
            return output;
        }
        check_bst_return leftAns = is_bst(root->left);
        check_bst_return rightAns = is_bst(root->right);

        int maximum = max(root->data, max(leftAns.maximum, rightAns.maximum));
        int minimum = min(root->data, min(leftAns.minimum, rightAns.minimum));
        bool output_final = (root->data > leftAns.maximum) && (root->data <= rightAns.minimum) && leftAns.check_bst && rightAns.check_bst;

        check_bst_return output;
        output.maximum = maximum;
        output.minimum = minimum;
        output.check_bst = output_final;
        return output;
    }
bool BST(BinaryTreeNode<int> *root){

    return is_bst(root).check_bst;
       
}
} 

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printTree(root);
    bool ans = BST(root);
    if (ans)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}