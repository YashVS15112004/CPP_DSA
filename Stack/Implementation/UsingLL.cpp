#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;

    StackNode(int a) {
        data = a;
        next = NULL;
    }
};
class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        StackNode*temp=new StackNode(x);
        temp->next=top;
        top=temp;
    }

    int pop() {
        if(top==NULL)return -1;
        int x=top->data;
        top=top->next;
        return x;
    }

    MyStack() { top = NULL; }
};
int main()
{
MyStack s;
// Assuming s is the stack and the numbers to push are in the given order
s.push(95);
cout<<s.pop()<<endl;     // 2
s.push(14);  // 1 14
cout<<s.pop()<<endl;     // 2
s.push(27);  // 1 27
cout<<s.pop()<<endl;     // 2
}