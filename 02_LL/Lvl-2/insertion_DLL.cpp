// Doubly Linked List

#include <iostream>
#include <vector>

using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void PrintNode(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int GetLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void InsertAtHead(Node *&head, Node *&tail, int data)
{
    // create Node -> check is Null -> insert -> update head
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void InsertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void InsertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    Node *newNode = new Node(data);

    if (position == 1)
    {
        InsertAtHead(head, tail, data);
        return;
    }
    int len = GetLength(head);
    if (position > len)
    {
        InsertAtTail(head, tail, data);
        return;
    }
    int i = 1;
    Node *prevNode = head;
    while (i < position - 1)
    {
        i++;
        prevNode = prevNode->next;
    }
    newNode->next = prevNode->next;
    prevNode->next->prev = newNode;

    newNode->prev = prevNode;
    prevNode->next = newNode;
}

int main()
{

    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    cout << endl;
    Node *head = first;
    Node *tail = third;
    PrintNode(head);

    // insertion in Doubly Linked List
    InsertAtHead(head, tail, 101);
    cout << endl;
    PrintNode(head);

    InsertAtTail(head, tail, 901);
    cout << endl;
    PrintNode(head);

    InsertAtPosition(head, tail, 111, 2);
    cout << endl;
    PrintNode(head);

    return 0;
}