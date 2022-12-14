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

Node *divide(Node*start){
    
    Node*head = start;
    Node*newnode = new Node(0);
    Node*newhead =newnode;
    Node*prev=NULL;
    while (head!=NULL)
    {
        if(head->data%2==0){
            Node*temp=head->next;
            newnode->next=head;
            prev->next=temp;
            if(temp!=NULL){
            prev=head;
            newnode=newnode->next;
            newnode->next=NULL;
            head=temp;
            }
            else{
            newnode=newnode->next;
            head=prev;
            }

        }
        else{
            prev=head;
            head=head->next;
        }
    }
    prev->next=newhead->next;
    newhead=newhead->next;
    return start;
}


int main()
{

    Node *head = NULL;
    head = push(head, 5);
    head = push(head, 4);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);
    Print(head);
    head=divide(head);
    Print(head);

}