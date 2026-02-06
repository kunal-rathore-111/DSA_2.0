 #include<iostream>

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
        front = -1;
        rear = -1;
        this->size = size;
    }
    
    bool isEmpty()
    {
        if(front == -1 && rear == -1)return true;
        return false;
    }
    
    void push(int val){
        // one ele, full, circular, normal
        if((rear == size-1 && front == 0) || (rear == front-1))
        {
            cout<<"Queue is full\n";
            return;
        }
        if(front == -1 && rear ==  -1)
        {
            rear++,front++;
            arr[rear] = val;
            return;
        }
        if(rear == size-1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
            return;
        }
        else{
            rear++;
            arr[rear] = val;
            return;            
        }
    }
    
    void popp(){
        if(isEmpty())
        {
            cout<<"Queue is empty\n";
            return;
        }
        if(rear == front)
        {
            front = -1;
            rear = -1;
        }
        if(front == size-1)
        {
            front = 0;
        }
        else{
            front++;
        }
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
        return arr[rear];
    }
};


int main()
{
    Queue q(5);
    
    cout << "Is empty: " << q.isEmpty() << endl;
    
    q.push(10);
    cout << "Pushed 10" << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    
    q.push(20);
    cout << "Pushed 20" << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    
    q.push(30);
    cout << "Pushed 30" << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    
    q.popp();
    cout << "Popped" << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    
    q.popp();
    cout << "Popped" << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    
    q.popp();
    cout << "Popped" << endl;
    cout << "Is empty: " << q.isEmpty() << endl;

    return 0;
}