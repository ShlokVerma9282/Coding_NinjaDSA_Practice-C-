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
void *split(Node *head, Node *a, Node *b)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    a = head;
    b = slow->next;
    slow->next = NULL;
}
Node *merge(Node *Fir_Link, Node *Sec_Link)
{
    Node *newnode = new Node(0);
    Node *newhead = newnode;
    while (Fir_Link != NULL && Sec_Link != NULL)
    {
        if (Fir_Link->data <= Sec_Link->data)
        {
            newnode->next = Fir_Link;
            Fir_Link = Fir_Link->next;
            newnode = newnode->next;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = Sec_Link;
            Sec_Link = Sec_Link->next;
            newnode = newnode->next;
            newnode->next = NULL;
        }
    }
    while (Fir_Link != NULL)
    {
        newnode->next = Fir_Link;
        Fir_Link = Fir_Link->next;
        newnode = newnode->next;
        newnode->next = NULL;
    }
    while (Sec_Link != NULL)
    {
        newnode->next = Sec_Link;
        Sec_Link = Sec_Link->next;
        newnode = newnode->next;
        newnode->next = NULL;
    }
    newhead = newhead->next;
    return (newhead);
}

void mergesort(Node *head)
{
    Node *final = head;
    Node *a;
    Node *b;
    if (final == NULL || final->next == NULL)
    {
        return;
    }
    split(final, a, b);
    mergesort(a);
    mergesort(b);
    head = merge(a, b);
}

int main()
{

    Node *head = NULL;
    head = push(head, 12);
    head = push(head, 10);
    head = push(head, 43);
    head = push(head, 25);
    mergesort(head);
    Print(head);
}