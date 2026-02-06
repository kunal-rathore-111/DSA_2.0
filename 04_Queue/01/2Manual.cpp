

#include <iostream>
#include <vector>

using namespace std;

class Queue
{
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int size)
    {
        arr = new int[size];
        front = 0;
        rear = 0;
        this->size = size;
    }
    
    bool isEmpty()
    {
        if(front == rear)return true;
        return false;
    }
    
    void push(int val){
        if(rear == size) {cout<<"Queue is full\n"; return;}
        arr[rear++]= val;
    }
    
    void popp(){
        if(isEmpty())
        {
            cout<<"Queue is empty\n";
            return;
        }
        arr[front++] = -1;
        if(front==rear) 
            rear = front = 0;
    }

    int getFront()
    {
        if(isEmpty())
        {
         cout<<"Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
    
    int getRear()
    {
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        return arr[rear-1];
    }
    
    int getSize() {return rear-front;}
};


int main(){
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<"Size of q- "<<q.getSize()<<endl<<endl;
    cout<<"Pushing 6 in q"<<endl<<endl;
    q.push(6);
    
    cout<<"Popped in q"<<endl<<endl;
    q.popp();
    cout<<"Is q empty- "<<q.isEmpty()<<endl<<endl;
    cout<<"Front in q- "<<q.getFront()<<endl<<endl;
    cout<<"Rear in q- "<<q.getRear()<<endl<<endl;
    return 0;
}