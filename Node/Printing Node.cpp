#include <iostream>
using namespace std;
#include "Node.cpp"

void takeInput(){
    int data;
    cin>>data;
    Node *head =NULL;
    Node *tail =NULL;

    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head ==NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next=newnode;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

void Print(Node *head){
    while (head !=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    
}

int main(){
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node *head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    Print(takeInput());    
}