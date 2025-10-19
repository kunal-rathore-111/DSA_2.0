
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

Node *reverseLL(Node *&head)
{
    if (head == NULL)
    {
        cout << "NO LIST EXISTS";
        return head;
    }
    Node *prev = NULL;
    Node *current = head;
    Node *right = current->next;
    while (current != NULL)
    {
        current->next = prev;
        prev = current;
        current = right;
        if (right != NULL)
            right = right->next;
    }
    return prev;
}

int main()
{

    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node *head = first;

    cout << "Before reversing- ";
    printLL(head);
    cout << endl;
    head = reverseLL(head);
    cout << "After reversing- ";
    printLL(head);
    cout << endl;

    return 0;
}