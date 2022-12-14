#include <iostream>
#include <queue>
#include "BinaryTree.h"
using namespace std;

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
BinaryTreeNode<int> *tree(int *postorder, int *inorder, int ps, int pe, int is, int ie)
{
    if (ps > pe)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[pe]);

    int k = 0;
    for (int i = is; i <= ie; i++)
    {
        if (postorder[pe] == inorder[i])
        {
            k = i;
            break;
        }
    }

    int lps = ps;              // left prestart
    int lis = is;              // left instart
    int lie = k - 1;           // left inend
    int lpe = lie - lis + lps; // left  pre end

    int rps = lpe + 1; // right prestart
    int rpe = pe - 1;  //  right preend
    int ris = k + 1;   // right instart
    int rie = ie;      // right inend

    root->left = tree(postorder, inorder, lps, lpe, lis, lie);
    root->right = tree(postorder, inorder, rps, rpe, ris, rie);

    return root;
}
BinaryTreeNode<int> *getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength)
{
    return tree(postorder, inorder, 0, postLength - 1, 0, inLength - 1);
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
}