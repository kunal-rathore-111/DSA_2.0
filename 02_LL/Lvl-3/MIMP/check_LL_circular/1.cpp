
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

bool isCircular(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        if (temp == head)
            return true;
    }
    return false;
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
    fifth->next = first;

    Node *head = first;
    cout << "LL is cicrualar?- " << isCircular(head) << endl;

    return 0;
}