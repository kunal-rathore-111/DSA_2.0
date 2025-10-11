
// 1) create circular singly LL and add node by digit instead of position

#include <iostream>
using namespace std;

// circular LL class
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        data = 0;
        prev = NULL;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    // if list is empty
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

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    // if list is empty
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

void addByDigit(Node *&head, Node *&tail, int data, int digit)
{
    Node *newNode = new Node(data);
    if (digit == head->data)
    {
        // insertAtHead
        insertAtHead(head, tail, data);
        return;
    }
    if (digit == tail->data)
    {
        // insertAtTail
        insertAtTail(head, tail, data);
        return;
    }
    // at middle
    int val = head->data;
    Node *current = head;
    while (val != digit)
    {
        current = current->next;
        val = current->data;
    }

    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    first->next = second;
    second->next = third;

    second->prev = first;
    third->prev = second;

    Node *head = first;
    Node *tail = third;

    cout << endl;
    printLL(head);

    addByDigit(head, tail, 90, 20); // add node where digit is 20
    cout << "Adding by digit- " << endl;
    printLL(head);
    cout << endl;

    addByDigit(head, tail, 0, 10); // add node where digit is 10 at head
    cout << "Adding at head- " << endl;
    printLL(head);
    cout << endl;

    addByDigit(head, tail, 111, 30); // add node where digit is 30 at tail
    cout << "Adding at tail- " << endl;
    printLL(head);
    cout << endl;

    addByDigit(head, tail, 999, 111); // add node where digit is 111
    cout << "Adding by tail- " << endl;
    printLL(head);
    cout << endl;

    return 0;
}
