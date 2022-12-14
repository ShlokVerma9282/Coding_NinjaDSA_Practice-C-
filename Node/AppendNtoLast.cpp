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
        next = 0;
    }
};
Node* push(Node *head, int data)
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

Node *appendTolast(Node *head, int target)
{
    Node *pointer = new Node(0);
    Node *tail = head;
    int count = 0;
    while (tail != NULL && count != target - 1)
    {
        tail = tail->next;
        count++;
    }
    Node *temp = tail->next;
    tail->next = NULL;
    pointer->next = head;
    head = temp;
    Node *newTail = head;

    Node *prev = NULL;
    while (newTail != NULL)
    {
        prev = newTail;
        newTail = newTail->next;
    }
    prev->next = pointer->next;
    return head;
}

int main()
{


    Node *head = NULL;
    head=push(head,5);
    head=push(head,4);
    head=push(head,3);
    head=push(head,2);
    head=push(head,1);
    head=push(head,0);
    Print(head);
    head = appendTolast(head, 2);
    Print(head);
}