

// using counting

// using 2 node pointer
// can also possible by map and creating new list

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

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void sortLL(Node *head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return;
    }
    if (head->next == NULL)
    {
        cout << "List has only one node" << endl;
        return;
    }

    int zero = 0, one = 0, two = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            zero++;
        else if (temp->data == 1)
            one++;
        else
            two++;

        temp = temp->next;
    }

    temp = head;
    while (zero--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    while (one--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    while (two--)
    {
        temp->data = 1;
        temp = temp->next;
    }
}

int main()
{

    Node *first = new Node(1);
    Node *second = new Node(1);
    Node *third = new Node(0);
    Node *fourth = new Node(0);
    Node *fifith = new Node(2);
    Node *sixth = new Node(2);
    Node *seventh = new Node(0);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifith;
    fifith->next = sixth;
    sixth->next = seventh;

    Node *head = first;

    sortLL(head);
    cout << "After sorting the list is- ";
    printLL(head);
    cout << endl;
}