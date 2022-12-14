#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
Node *push(Node *head, int data)
{

    Node *new_node = new Node(data);

    new_node->next = head;

    head = new_node;

    return head;
}
void Print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverse(Node *head){
    Node *curr =head;
    Node *next = NULL;
    Node *prev = NULL;
    while (curr!=NULL)
    {
        next = curr->next;
        curr->next=prev;
        prev = curr;
        curr=next;
    }
    head=prev;
}

bool Palindrome(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    int mid = count / 2;
    Node *newnode = head;
    count = 0;
    while (count != mid)
    {
        count++;
        newnode = newnode->next;
    }
    Node *newhead =new Node(0);
    newhead->next=newnode->next;
    newnode->next=NULL;
    Node*newtemp=newhead->next;
    newhead=newtemp;
    newhead=reverse(newhead);
    while (newhead != NULL)
    {
        if (head->data != newhead->data)
        {
            return false;
        }
        head = head->next;
        newhead = newhead->next;
    }
    return true;
}

int main()
{

    Node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 2);
    head = push(head, 1);
    bool a = Palindrome(head);
    if (a)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}