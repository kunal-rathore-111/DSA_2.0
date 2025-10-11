
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

Node *reverseKgrpList(Node *&head, int k)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return head;
    }
    if (getLen(head) < k)
    {
        return head;
    }
    // now
    // Step A: reverse first k
    Node *left = NULL;
    Node *current = head;
    Node *right = current->next;
    int count = 0;
    while (count < k)
    {
        current->next = left;
        left = current;
        current = right;
        if (right != NULL)
        {
            right = right->next;
        }
        count++;
    }
    head->next = reverseKgrpList(current, k);
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
    cout << "Before reversing- ";
    printList(head);
    int k = 2;
    cout << "enter the value of k- ";
    cin >> k;
    head = reverseKgrpList(head, k);
    cout << "After reversing- ";
    printList(head);

    return 0;
}