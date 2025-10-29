#include <iostream>
#include <stack>

using namespace std;

void recBottom(stack<int> &k, int &target)
{
    // steps = 1) get the elemnt => pop the element => call rec => if empty push temp and return => backtrack by putting the temp again
    if (k.empty())
    {
        k.push(target);
        return;
    }

    int temp = k.top();
    k.pop();
    recBottom(k, target);
    // backtrack
    k.push(temp);
}

void insertAtBottom(stack<int> &k)
{
    // edge case if stack is empty
    if (k.empty())
    {
        cout << "Stack empty" << endl;
        return;
    }
    // store the top element which will have to be at bottom
    int target = k.top();
    // pop that element so no more exists in stack
    k.pop();
    // rec to put that element at bottom
    recBottom(k, target);
}

int main()
{
    stack<int> k;

    k.push(10);
    k.push(20);
    k.push(30);
    k.push(40);
    k.push(50);

    insertAtBottom(k);

    cout << "Stack after putting at bottom- ";
    while (!k.empty())
    {
        cout << k.top() << " ";
        k.pop();
    }
    cout << endl;

    return 0;
}