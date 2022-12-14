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
Node*deleteNNode(Node*start,int target,int num){
    int count =0;
    int num_count=0;
    Node*head=start;
    Node*prev=NULL;
    while (count!=target-1)
    {
        head=head->next;
        count++;
        if(head==NULL){
        return 0;  
        }

    }
    while (num_count!=num)
    {
        prev=head;
        head=head->next;
        if(head==NULL){
        return 0;
        }
        prev->next=head->next;
        head->next=NULL;
        head=prev;
        num_count++;
    }
    return start;

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
    Print(head);
    head=deleteNNode(head,10,1);
    Print(head);
    
}