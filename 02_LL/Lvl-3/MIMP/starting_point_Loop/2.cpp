

// using slow fast (floyd cycle)
// find the loop exists then, set slow to head again and traverse by slow and fast by +1 only

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

Node *sendStartOfLoop(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        if (slow == fast && slow != head)
        {
            slow = head;
            break;
        }
        fast = fast->next;
        slow = slow->next;

        if (fast != NULL)
        {
            fast = fast->next;
        }
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    cout << "No loop present\n";
    return head;
}

int main()
{

    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    fifth->next = third;

    Node *head = first;

    cout << sendStartOfLoop(head)->data << endl;
    return 0;
}