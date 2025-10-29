#include <iostream>
#include <stack>

using namespace std;

void recPutAtBelow(stack<int> &k, int target)
{
    if (k.empty())
    {
        k.push(target);
        return;
    }
    int temp = k.top();
    k.pop();
    recPutAtBelow(k, target);
    // back
    k.push(temp);
}

void recRev(stack<int> &k)
{

    if (k.empty())
    {
        return;
    }
    int target = k.top();
    k.pop();

    recRev(k);
    recPutAtBelow(k, target);
}

int main()
{
    stack<int> k;
    k.push(10);
    k.push(20);
    k.push(30);
    k.push(40);
    k.push(50);

    if (k.empty())
    {
        cout << "stack is empty" << endl;
    }
    recRev(k);

    cout << "On reverse- ";
    while (!k.empty())
    {
        cout << k.top() << " ";
        k.pop();
    }
    cout << endl;

    return 0;
}