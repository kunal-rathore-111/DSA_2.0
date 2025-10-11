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
    ~Node()
    {
        cout << "Dtor called" << endl;
    }
};

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

void Print(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void DeleteAtHead(Node *&head, Node *&tail)
{
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    head->prev = NULL;
    delete temp;
    return;
}

void DeleteAtTail(Node *&head, Node *&tail)
{
    Node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
    return;
}

void DeleteAtPosition(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "Linked-List is empty" << endl;
        return;
    }
    if (position == 1)
    {
        DeleteAtHead(head, tail);
        return;
    }
    int len = GetLength(head);
    if (position > len || position == 0)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (len == position)
    {
        DeleteAtTail(head, tail);
        return;
    }
    int i = 1;
    Node *current = head;
    while (i < position)
    {
        current = current->next;
        i++;
    }
    Node *left = current->prev;
    Node *right = current->next;
    left->next = right;
    right->prev = left;
    current->prev = NULL;
    current->next = NULL;
    delete current;
}

int main()
{

    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;

    second->prev = first;
    third->prev = second;
    fourth->prev = third;

    Node *head = first;
    Node *tail = fourth;

    Print(head);
    cout << endl;

    DeleteAtHead(head, tail);
    cout << "After deletion at head- ";
    Print(head);
    cout << endl;

    DeleteAtTail(head, tail);
    cout << "After deletion at tail- ";
    Print(head);
    cout << endl;

    DeleteAtPosition(head, tail, 0);
    cout << "After deletion at position- ";
    Print(head);
    cout << endl;

    return 0;
}