
// using map

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

bool checkLoop(Node *&head)
{
    // create map
    map<Node *, bool> mp;
    Node *temp = head;
    while (temp != NULL)
    {
        if (mp[temp])
        {
            return true;
        }
        else
        {
            mp[temp] = true;
            temp = temp->next;
        }
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

    Node *head = first;

    cout << checkLoop(head) << endl;
    return 0;
}