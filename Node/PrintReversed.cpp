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

void Printreverse(Node*head,int count){
    if (head!=NULL)
    {
        count++;
        Printreverse(head->next,count);
        cout<<head->data<<" ";
    }
    if (count==1)
    {
        cout<<endl;
    }
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
    Printreverse(head,0);
    Print(head);
}