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

Node* delete_occurance(Node* head){
    Node*lower = head;
    Node*higher = lower->next;
    while (higher!=NULL)
    {
        if (lower->data == higher->data)
        {   Node*temp = higher->next;
            lower->next=temp;
            higher->next=NULL;
            if(lower->next!=NULL){
            higher=lower->next;
            }
            else{
              return head;
              }
        }
        else{
            lower=lower->next;
            higher=lower->next;
        }
    }
    return head;
    
}
int main()
{


    Node *head = NULL;
    head=push(head,5);
    head=push(head,5);
    head=push(head,4);
    head=push(head,3);
    head=push(head,3);
    head=push(head,2);
    head=push(head,1);
    head=push(head,1);
    head=push(head,1);
    head=push(head,0);
    head=push(head,0);
    Print(head);
    head = delete_occurance(head);
    Print(head);
}