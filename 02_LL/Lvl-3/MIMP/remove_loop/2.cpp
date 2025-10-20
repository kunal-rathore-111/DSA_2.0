

// using slow fast

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
    Node *slow = head;
    Node *fast = head;

    // 1) find the loop exists
    while (fast != NULL)
    {
        if (slow == fast && slow != head)
        {
            slow = head;
            break;
        }
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    // 2) find starting point, and keep prev node track
    Node *prev = fast;
    while (fast != NULL)
    {
        if (slow == fast)
        {
            // 3) if starting point found set prev to null, loop removed
            prev->next = NULL;
            return;
        }

        prev = fast;
        fast = fast->next;
        slow = slow->next;
    }
    return;
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
    cout << "List after removing loop using find starting point slow fast method- ";
    PrintLL(head);
    cout << endl;
    return 0;
}