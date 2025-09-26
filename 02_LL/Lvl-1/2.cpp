

// insert in middle

// Insertion at head and tail in LL

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data, Node *&tail)
{

    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node *&head, int data, Node *&tail)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void printLL(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int findLLlength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtPosition(Node *&head, int digit, Node *&tail, int position)
{
    int len = findLLlength(head);
    if (position == 1)
    {
        insertAtHead(head, digit, tail);
    }

    else if (position >= len)
    {
        insertAtTail(head, digit, tail);
    }
    else
    {
        // insert in middle
        Node *prev = head;
        while (position != 2)
        {
            position--;
            prev = prev->next;
        }
        Node *current = prev->next;
        Node *newNode = new Node(digit);

        newNode->next = current;
        prev->next = newNode;
    }
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, 30, tail);
    insertAtTail(head, 10, tail);
    insertAtTail(head, 20, tail);
    insertAtHead(head, 40, tail);

    insertAtPosition(head, 100, tail, 2);

    cout << "Printing LL: ";
    printLL(head);
    return 0;
}