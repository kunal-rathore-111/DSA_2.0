#include <iostream>
#include <stack>

using namespace std;

void putAtcorrectFunc(stack<int> &k, int target)
{
    if (k.empty())
    {
        k.push(target);
        return;
    }
    if (k.top() > target)
    {
        k.push(target);
        return;
    }

    int temp = k.top();
    k.pop();
    putAtcorrectFunc(k, target);
    k.push(temp);
}

void sortStack(stack<int> &k)
{
    if (k.empty())
        return;

    int target = k.top();
    k.pop();
    sortStack(k);
    putAtcorrectFunc(k, target);
}

int main()
{
    stack<int> k;

    k.push(50);
    k.push(20);
    k.push(40);
    k.push(30);
    k.push(10);

    sortStack(k);

    cout << "Stack after sorting- ";
    while (!k.empty())
    {
        cout << k.top() << " ";
        k.pop();
    }
    cout << endl;

    return 0;
}