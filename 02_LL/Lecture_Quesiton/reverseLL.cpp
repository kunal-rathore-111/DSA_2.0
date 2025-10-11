
// eg-> given, 10,20,30,40,50,60 k = 3
// then,
// op-> 30, 20, 10, 60, 50, 40
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

void printList(Node *&head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "list is empty";
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverseList(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return head;
    }

    // now
    // Step A: create require ptr
    Node *left = NULL;
    Node *current = head;
    Node *right = current->next;

    // Step B: reverse node
    while (current != NULL)
    {

        current->next = left;
        left = current;
        current = right;
        if (right != NULL)
        {
            right = right->next;
        }
    }

    return left;
}

int main()
{

    Node *first = new Node(5);
    Node *second = new Node(15);
    Node *third = new Node(25);
    Node *fourth = new Node(35);
    Node *fifth = new Node(45);
    Node *sixth = new Node(55);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    Node *head = first;

    printList(head);
    head = reverseList(head);
    cout << "After reversing- " << endl;
    printList(head);

    return 0;
}