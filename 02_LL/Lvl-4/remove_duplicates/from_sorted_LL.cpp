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

void removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        cout << "List is null " << endl;
        return;
    }
    if (head->next == NULL)
    {
        cout << "One one node is present " << endl;
        return;
    }
    // create two notes current and nextNode
    Node *current = head;
    Node *nextNode = current->next;
    while (nextNode != NULL)
    {
        if (current->data != nextNode->data)
        {
            current = current->next;
            nextNode = nextNode->next;
        }
        else
        {
            // next node ko remove kardo and current ke next ko nextNode kae next par laga do
            Node *temp = nextNode;          // point the node
            current->next = nextNode->next; // link the current node the next node by skipping one node(temp vali)
            nextNode = nextNode->next;      // next node pointer move to new node
            temp->next = NULL;              // unlinked the node to delete
            delete temp;                    // node deleted
        }
    }
}

int main()
{

    Node *first = new Node(10);
    Node *second = new Node(10);
    Node *third = new Node(30);
    Node *fourth = new Node(30);
    Node *fifith = new Node(40);
    Node *sixth = new Node(40);
    Node *seventh = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifith;
    fifith->next = sixth;
    sixth->next = seventh;

    Node *head = first;

    removeDuplicates(head);
    cout << "After removing duplicates list is- ";
    printLL(head);
    cout << endl;
}