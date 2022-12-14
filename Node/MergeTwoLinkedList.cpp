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

Node*Merge(Node*Fir_Link,Node*Sec_Link){
    Node*newnode = new Node(0);
    Node*newhead = newnode;
    while (Fir_Link!=NULL && Sec_Link!=NULL)
    {
        if (Fir_Link->data<=Sec_Link->data)
        {
            newnode->next=Fir_Link;
            Fir_Link=Fir_Link->next;
            newnode=newnode->next;
            newnode->next=NULL;
        }
        else{
            newnode->next=Sec_Link;
            Sec_Link=Sec_Link->next;
            newnode=newnode->next;
            newnode->next=NULL;
        }
    }
    while (Fir_Link!=NULL)
    {
        newnode->next=Fir_Link;
        Fir_Link=Fir_Link->next;
        newnode=newnode->next;
        newnode->next=NULL;
    }
    while (Sec_Link!=NULL)
    {
        newnode->next=Sec_Link;
        Sec_Link=Sec_Link->next;
        newnode=newnode->next;
        newnode->next=NULL;
    }
    newhead=newhead->next;    
    return(newhead);

}

int main()
{

    Node *head = NULL;
    head = push(head, 41);
    head = push(head, 32);
    head = push(head, 23);
    head = push(head, 11);
    Node *shead = NULL;
    shead = push(shead, 44);
    shead = push(shead, 33);
    shead = push(shead, 22);
    shead = push(shead, 12);
    Node *nhead =NULL;
    nhead = Merge(head,shead);
    Print(nhead);

}