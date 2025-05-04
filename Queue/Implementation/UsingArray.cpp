#include<bits/stdc++.h>
using namespace std;
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
void MyQueue :: push(int x)
{
    if(rear>=100005) return;
    else arr[rear++] = x;
}
int MyQueue :: pop()
{
    if(front>=rear) return -1;
    else return arr[front++];
}
int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
}