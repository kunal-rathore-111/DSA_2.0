
// creating reverse LL and check

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

Node *createReverseLL(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *right = current->next;
    while (current != NULL)
    {
        current->next = prev;
        prev = current;
        current = right;
        if (right != NULL)
        {
            right = right->next;
        }
    }
    return prev;
}

bool isPalindrome(Node *head1, Node *head2)
{

    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 != NULL)
    {
        if (temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return true;
}

int main()
{

    Node *first1 = new Node(10);
    Node *second1 = new Node(20);
    Node *third1 = new Node(20);
    Node *fourth1 = new Node(10);

    first1->next = second1;
    second1->next = third1;
    third1->next = fourth1;

    Node *head1 = first1;
    cout << "Before reversing- ";
    printLL(head1);
    cout << endl;

    Node *first2 = first1;
    Node *second2 = second1;
    Node *third2 = third1;
    Node *fourth2 = fourth1;

    first2->next = second2;
    second2->next = third2;
    third2->next = fourth2;

    Node *head2 = first2;
    head2 = createReverseLL(head2);
    cout << "After reversing- ";
    printLL(head2);
    cout << endl;

    cout << "List isPlaindrome- " << isPalindrome(head1, head2) << endl;

    return 0;
}