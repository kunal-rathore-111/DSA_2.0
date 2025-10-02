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

    ~Node()
    {
        cout << "destructre called" << endl;
    }
};

void InsertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    newNode->next = head;
    head = newNode;
    if (tail == NULL)
    {
        tail = newNode;
    }
}

void InsertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    tail->next = newNode;
    tail = newNode;
    if (head == NULL)
    {
        head = newNode;
    }
}

int findLen(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void InsertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    int len = findLen(head);
    if (position == 1)
    {
        InsertAtHead(head, tail, data);
    }
    else if (position >= len)
    {
        InsertAtTail(head, tail, data);
    }
    else
    {
        Node *newNode = new Node(data);

        Node *prev = head;
        int i = 0;
        while (i < position - 2)
        {
            prev = prev->next;
            i++;
        }
        Node *curr = prev->next;

        newNode->next = curr;
        prev->next = newNode;
    }
}

void PrintLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteFromPosition(Node *&head, Node *&tail, int pos)
{
    int len = findLen(head);
    if (pos == 1)
    {
        // delete from head
        Node *temp = head;
        head = head->next;

        // cal destructur for temp
        delete temp;
    }
    else if (pos >= len)
    {
        // delete from tail
        Node *temp = head;
        Node *prev = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        tail = prev;
        tail->next = NULL;
        // destructure for temp
        delete temp;
    }
    else
    {
        // delete from position
        int i = 0;
        Node *prev = head;
        while (i < pos - 2)
        {
            prev = prev->next;
            i++;
        }
        Node *temp = prev->next;
        prev->next = temp->next;
        temp->next = NULL;
        // call destructure for temp
        delete temp;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    InsertAtHead(head, tail, 32);
    InsertAtHead(head, tail, 22);
    InsertAtTail(head, tail, 42);
    InsertAtTail(head, tail, 12);
    InsertAtPosition(head, tail, 2, 3);

    PrintLL(head);

    deleteFromPosition(head, tail, 9);
    cout << "Printing after deleting from position- ";

    PrintLL(head);

    return 0;
}