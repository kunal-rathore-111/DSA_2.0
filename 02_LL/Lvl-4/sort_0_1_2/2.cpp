
// using 3 dummy nodes

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

Node *deleteNodeFunc(Node *&n)
{
    Node *newHead = n->next;
    Node *temp = n;
    temp->next = NULL;
    delete temp;
    return newHead;
}

Node *sortLL(Node *head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return NULL;
    }
    if (head->next == NULL)
    {
        cout << "List has only one node" << endl;
        return head;
    }

    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *traverseNode = head;
    while (traverseNode != NULL)
    {
        // point the node, make the traverse node ahead, unlink the pointed node, link to the corresponding node
        Node *currentNode = traverseNode;
        traverseNode = traverseNode->next;
        currentNode->next = NULL;

        if (currentNode->data == 0)
        {
            zeroTail->next = currentNode;
            zeroTail = currentNode;
        }
        else if (currentNode->data == 1)
        {
            oneTail->next = currentNode;
            oneTail = currentNode;
        }
        else
        {
            twoTail->next = currentNode;
            twoTail = currentNode;
        }
    }

    // now link all three lists
    // move heads of ones and twos node to next so they might be one the first node or on null
    oneHead = deleteNodeFunc(oneHead);

    twoHead = deleteNodeFunc(twoHead);

    // then check and link to zerotail
    if (oneHead != NULL)
    {
        zeroTail->next = oneHead;
        // then link the twovali node to one
        if (twoHead != NULL)
        {
            oneTail->next = twoHead;
        }
    }
    else
    { // means no one are present so link to two directly
        if (twoHead != NULL)
        {
            zeroTail->next = twoHead;
        }
    }

    // remove one ka head vali node;
    zeroHead = deleteNodeFunc(zeroHead);

    // return new head
    return zeroHead;
}

int main()
{

    Node *first = new Node(0);
    Node *second = new Node(2);
    Node *third = new Node(2);
    Node *fourth = new Node(1);

    first->next = second;
    second->next = third;
    third->next = fourth;

    Node *head = first;

    head = sortLL(head);
    cout << "After sorting the list is- ";
    printLL(head);
    cout << endl;
}