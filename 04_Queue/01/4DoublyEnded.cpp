
#include<iostream>

using namespace std;

class Deque{
    int *arr;
    int size;
    int front;
    int rear;
    public:
    Deque(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void pushRear(int val)
    {
        if((rear== size-1 && front == 0 )|| (front -1 == rear))
        {
            cout<<"Q is full\n";
            return;
        }
        if(rear == -1 && front == -1)
        {
            rear ++,front++;
        }
        if(rear == size-1 && front != 0)
        {
            rear = 0;
        }
        else{
            rear++; 
        }
        arr[rear]= val;
    }

    void pushFront(int val)
    {
        if((rear== size-1 && front == 0 ) || (front -1 == rear))
        {
            cout<<"Q is full\n";
            return;
        }
        if(rear == -1 && front == -1)
        {
            rear ++,front++;
        }
        if(rear != size-1 && front == 0)
        {
            front = size-1;
        }
        else{
            front-- ; 
        }
        arr[front]= val;
    }
    void popFront(){
       if(front == -1 && rear == -1)
       {
           cout<<"Q is empty\n";
           return;
       }
       if(front == rear)
       {
        front  = rear = -1;
       }
       if(front == size-1)
       {
        front  = 0;
       }
       else{
        front ++;
       }
    }
    void popRear(){
       if(front == -1 && rear == -1)
       {
           cout<<"Q is empty\n";
           return;
       }
       if(front == rear)
       {
        front  = rear = -1;
       }
       if(rear == 0)
       {
        rear = size-1 ;
       }
       else{
        rear--;
       }
    }
};

int main(){
    Deque dq(5);

    dq.pushRear(10);
    cout << "Pushed rear 10" << endl;

    dq.pushFront(20);
    cout << "Pushed front 20" << endl;

    dq.pushRear(30);
    cout << "Pushed rear 30" << endl;

    dq.pushFront(40);
    cout << "Pushed front 40" << endl;

    dq.popFront();
    cout << "Popped front" << endl;

    dq.popRear();
    cout << "Popped rear" << endl;

    dq.popFront();
    cout << "Popped front" << endl;

    dq.popRear();
    cout << "Popped rear" << endl;

    return 0;
}
