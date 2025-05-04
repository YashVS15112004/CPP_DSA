#include<bits/stdc++.h>
using namespace std;
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};
void MyQueue:: push(int x)
{
        QueueNode *node = new QueueNode(x);
        if(front==NULL) 
        {
            rear = node;
            front = rear;
        }
        else
        {
            rear->next = node;
            rear = node;
        }
}
int MyQueue :: pop()
{
        if(front==NULL) return -1;
        else 
        {
            int ele = front->data;
            front = front->next;
            return ele;
        }
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