
// using map -> check is there any loop if yes the send the starting point

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

void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *sendStaringOfLoop(Node *&head)
{
    // create map
    map<Node *, bool> mp;
    Node *temp = head;
    while (temp != NULL)
    {
        if (mp[temp])
        {
            return temp;
        }

        mp[temp] = true;
        temp = temp->next;
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
    fifth->next = NULL;

    Node *head = first;

    cout << sendStaringOfLoop(head)->data << endl;
    return 0;
}