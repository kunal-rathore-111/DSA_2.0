

// inplace -> by reversing half LL

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

Node *findMiddle(Node *head)
{
    // using slow fast
    Node *slow = head;
    Node *fast = head->next; // safe case for odd no.

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

Node *createReverseLLAfterMiddle(Node *middle)
{
    Node *prev = NULL;
    Node *current = middle;
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

bool isPalindrome(Node *head1, Node *middle)
{

    Node *temp1 = head1;
    Node *temp2 = middle->next;
    while (temp2 != NULL)
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

    Node *middle = findMiddle(head1);
    middle->next = createReverseLLAfterMiddle(middle->next);

    cout << "List isPlaindrome- " << isPalindrome(head1, middle) << endl;

    return 0;
}