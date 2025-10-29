

#include <iostream>

using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    // behaviours
    int getSize()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }
    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[top];
    }
    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;

        arr[top] = data;
        return;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
        return;
    }
};

int main()
{
    Stack st(10);
    cout << "Is stack empty- " << st.isEmpty() << endl;
    st.push(12);
    st.push(90);
    cout << "Top element is- " << st.getTop() << endl;
    cout << "Size is- " << st.getSize() << endl;
    return 0;
}