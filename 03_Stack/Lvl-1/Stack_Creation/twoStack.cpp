#include <iostream>
#include <vector>

using namespace std;

class Stack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }
    void push1(int data)
    {
        if (top1 == top2 - 1)
        {
            cout << "Stack1 overflow" << endl;
            return;
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }
    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Underflow stack1" << endl;
            return;
        }
        top1--;
    }
    void push2(int data)
    {
        if (top1 == top2 - 1)
        {
            cout << "Stack2 overflow" << endl;
            return;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }
    void pop2()
    {
        if (top2 == size)
        {
            cout << "Underflow stack2" << endl;
            return;
        }
        top2++;
    }
};

int main()
{
    Stack s(10);

    s.push1(1);
    s.push1(1);
    s.push1(1);
    s.push1(1);
    s.push1(1);
    s.push1(1);
    s.push1(1);
    s.push1(1);
    s.push1(1);
    s.push2(2);
    s.pop2();
    s.pop2();

    return 0;
}