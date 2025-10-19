
#include <iostream>
#include <vector>

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

int getLen(Node *&head)
{
    if (head == NULL)
    {
        cout << "list empty";
        return -1;
    }
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

int main()
{
    Node *first = new Node(5);
    Node *second = new Node(15);
    Node *third = new Node(25);
    //  Node * fourth = new Node(35);

    first->next = second;
    second->neaxt = third;
    // third->next = fourth;
    Node *head = first;

    int size = getLen(head);
    if (size % 2 == 0)
        cout << size / 2;
    else
        cout << (size / 2) + 1;

    return 0;
}