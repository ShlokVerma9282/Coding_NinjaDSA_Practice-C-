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
        next = NULL;
    }
};
class stack
{
    Node *head;
    int size;

public:
    stack()
    {
        size = 0;
        head = NULL;
    }
    int getSize()
    {
        return size;
    }
    bool empty()
    {
        return size == 0;
    }
    void push(int element)
    {
        Node *newnode = new Node(element);
        newnode->next = head;
        head = newnode;
        size++;
    }
    void pop()
    {
        if (size == 0)
        {
            cout << "The Stack is empty" << endl;
            return ;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    int top()
    {
        if (size == 0)
        {
            cout << "The Stack is empty" << endl;
            return 0;
        }
        int ans = head->data;
        return ans;
    }
};
