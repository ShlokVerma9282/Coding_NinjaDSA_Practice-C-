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
Node *swap(Node *start, int target, int num)
{
    Node *head = start;
    Node *temp1 = NULL;
    Node *temp2 = NULL;
    Node *prev1 = NULL;
    Node *prev2 = NULL;
    int count = 0;
    while (count != num)
    {
        prev2 = head;
        head = head->next;
        count++;
        if (count == target)
        {
            prev1 = prev2;
            temp1 = head;
        }
    }
    temp2 = head;
    if (target == 0)
    {
        temp1 = start;
        if (prev2->next == NULL)
        {
            return 0;
        }
        Node *temp3 = temp1->next;
        temp1->next = temp2->next;
        temp2->next = temp3;
        prev2->next = temp1;
        start = temp2;
        return start;
    }
    prev1->next = temp2;
    if (prev2->next == NULL)
    {
        return 0;
    }
    Node *temp3 = temp2->next;
    temp2->next = temp1->next;
    prev2->next = temp1;
    temp1->next = temp3;
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
    head = swap(head, 0, 10);
    Print(head);
}