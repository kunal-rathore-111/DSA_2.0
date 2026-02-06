#include <iostream>
#include <queue>
using namespace std;

int main()
{

    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();
    cout << "first element is popped out" << endl;
    cout << "Size of queue is- " << q.size() << endl;
    if (q.empty())
        cout << "Q is empty\n";
    else
        cout << "Q is not empty\n";
    cout << "Front element is- " << q.front() << endl;
    cout << "Rear element is- " << q.back() << endl;

    return 0;
}