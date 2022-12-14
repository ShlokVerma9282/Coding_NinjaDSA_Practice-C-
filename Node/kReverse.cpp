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



Node*kreverse(Node *start,int k)
{
Node*head = start;
Node*prev = NULL;
Node*next = NULL;
int count = 0;
while (head!=NULL && count<k)
{
    next = head->next;
	head->next = prev;
	prev = head;
	head = next;
	count++;
}
if (next!=NULL)
{
    start->next=kreverse(next,k);
}
return prev;

}

int main()
{

    Node *head = NULL;
    head = push(head, 10);
    head = push(head, 9);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 6);
    head = push(head, 5);
    head = push(head, 4);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);
    head=kreverse(head,3);
    Print(head);
}