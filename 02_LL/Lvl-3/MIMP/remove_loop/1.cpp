
// using map
#include <iostream>
#include <map>

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

void PrintLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void removeLoop(Node *head)
{
    if (head == NULL)
        return;
    Node *current = head;
    Node *prev = head;
    map<Node *, bool> mp;
    while (current != NULL)
    {
        if (mp[current])
        {
            prev->next = NULL;
            return;
        }
        mp[current] = true;
        prev = current;
        current = current->next;
    }
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
    fifth->next = third;
    Node *head = first;

    removeLoop(head);
    cout << "List after loop removing- ";
    PrintLL(head);
    cout << endl;
    return 0;
}