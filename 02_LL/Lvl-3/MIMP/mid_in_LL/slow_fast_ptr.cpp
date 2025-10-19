
// slow and fast ptr
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

int slowFast(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return -1;
    }
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow->data;
}

int main()
{
    Node *first = new Node(5);
    Node *second = new Node(15);
    Node *third = new Node(25);
    Node *fourth = new Node(35);
    Node *fifth = new Node(45);

    first->next = second;
    second->next = third;
    third->next = fourth;
    // fourth->next = fifth;
    Node *head = first;

    cout << slowFast(head);

    return 0;
}