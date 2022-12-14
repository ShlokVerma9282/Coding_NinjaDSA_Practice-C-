#include <iostream>
using namespace std;
#include "Node.cpp"

Node* takeInput(){
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

void Count(Node *head,int count){
    while (head !=NULL)
    {
        count++;
        head = head->next;
    }
    cout<<"The Count is: "<<count<<endl;
}

void Print(Node *head){
    while (head !=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void PrintNode(Node *head,int target){
    int count =0;
    while (count !=target)
    {
        head =head->next;
        count++;
    }
    cout<<"The Data on Node is: "<<head->data<<endl;
}
int main(){

    Node *head = takeInput();
    Print(head);
    Count(head,0);
    PrintNode(head,0);    
}