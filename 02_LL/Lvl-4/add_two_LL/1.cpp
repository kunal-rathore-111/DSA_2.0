

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

Node *reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *current = head;

    while (current != NULL)
    {
        Node *nextN = current->next;
        current->next = prev;
        prev = current;
        current = nextN;
    }

    return prev;
}

Node *removeZeroes(Node *head)
{
    Node *temp = head;
    while (temp->data == 0 && temp->next != NULL)
    {
        Node *temp2 = temp;
        temp = temp->next;
        temp2->next = NULL;
        delete (temp2);
    }
    return temp;
}

Node *addLL(Node *head1, Node *head2)
{
    // edge cases
    if (head1 == NULL && head2 == NULL)
    {
        return NULL;
    }
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    // now, reverseList ->add-> reverseAns ->return
    Node *t1 = reverseLL(head1);
    Node *t2 = reverseLL(head2);
    Node *newNodeHead = new Node(-1);
    Node *newNodeTail = newNodeHead;
    int carry = 0;
    while (t1 != NULL && t2 != NULL)
    {
        int sum = t1->data + t2->data + carry;
        int digit = sum % 10;
        carry = sum / 10;

        if (newNodeHead->data == -1)
        {
            newNodeHead->data = digit;
        }
        else
        {
            // create Node
            Node *newNode = new Node(digit);
            newNodeTail->next = newNode;
            newNodeTail = newNode;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    while (t1 != NULL)
    {
        int sum = t1->data + carry;
        int digit = sum % 10;
        carry = sum / 10;
        if (newNodeHead->data == -1)
        {
            newNodeHead->data = digit;
        }
        else
        {
            // create Node
            Node *newNode = new Node(digit);
            newNodeTail->next = newNode;
            newNodeTail = newNode;
        }
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        int sum = t2->data + carry;
        int digit = sum % 10;
        carry = sum / 10;
        if (newNodeHead->data == -1)
        {
            newNodeHead->data = digit;
        }
        else
        {
            // create Node
            Node *newNode = new Node(digit);
            newNodeTail->next = newNode;
            newNodeTail = newNode;
        }
        t2 = t2->next;
    }

    while (carry)
    {
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        if (newNodeHead->data == -1)
        {
            newNodeHead->data = digit;
        }
        else
        {
            // create Node
            Node *newNode = new Node(digit);
            newNodeTail->next = newNode;
            newNodeTail = newNode;
        }
    }

    newNodeHead = reverseLL(newNodeHead);
    newNodeHead = removeZeroes(newNodeHead);
    return newNodeHead;
}

int main()
{

    Node *first = new Node(0);

    Node *head = first;

    Node *first2 = new Node(0);

    Node *head1 = first;
    Node *head2 = first2;

    Node *newList = addLL(head1, head2);

    cout << "After adding the list is- ";
    printLL(newList);
    cout << endl;
}
