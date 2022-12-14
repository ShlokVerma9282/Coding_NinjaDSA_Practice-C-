#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

void Count(Node *head, int count)
{
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    cout << "The Count is: " << count << endl;
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

Node *append(Node *head)
{
    int target;
    cout << "The Data is to be added at position: ";
    cin >> target;
    cout << endl;
    int data;
    cout << "The Data is: ";
    cin >> data;
    cout << endl;
    int count = 0;
    Node *newnode = new Node(data);
    Node *tail = head;
    if (target == 0)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    while (tail != NULL && count != target - 1)
    {
        tail = tail->next;
        count++;
    }
    if (tail != NULL)
    {
        Node *temp = tail->next;
        tail->next = newnode;
        newnode->next = temp;
    }
    return head;
}

int main()
{

    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node *head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;0
    Print(head);
    Count(head, 0);
    head = append(head);
    Print(head);
}