

// Dobuly ended using stl

#include<iostream>
#include<deque>

using namespace std;


int main()
{

    deque <int>dq;

    cout<<"Size- "<<dq.size()<<endl;
    dq.push_front(5);
    cout<<"Size- "<<dq.size()<<endl;
    dq.push_back(1);
    dq.push_back(4);
    cout<<"Size- "<<dq.size()<<endl;
    cout<<"Size- "<<dq.size()<<endl;
    cout<<"Front element- " <<dq.front()<<endl;
    dq.pop_front();
   cout<<"Back element- " <<dq.back()<<endl;
    dq.pop_back();
    cout<<"Size- "<<dq.size()<<endl;


}