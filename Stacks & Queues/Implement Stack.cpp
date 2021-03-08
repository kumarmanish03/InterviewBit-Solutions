#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

class Stack
{
public:
  int top;
  int arr[MAX];
  int push(int x);
  int pop();
  int peek();
  bool isEmpty();
  Stack()
  {
    top = -1;
  }
};

int Stack::push(int x)
{
  if (top >= MAX - 1)
  {
    cout << "Stack is Full Already\n";
    return 0;
  }

  top++;
  arr[top] = x;
  return x;
}

int Stack::pop()
{
  if (top < 0)
  {
    cout << "Stack is Empty\n";
    return -1;
  }

  top--;
  return arr[top + 1];
}

int Stack::peek()
{
  if (top < 0)
  {
    cout << "Stack is Empty\n";
    return 0;
  }

  cout << arr[top] << "\n";
  return arr[top];
}

bool Stack::isEmpty()
{
  if (top < 0)
  {
    cout << 1 << "\n";
    return 1;
  }
  else
  {
    cout << 0 << "\n";
    return 0;
  }
}

int main()
{
  Stack s;
  s.push(5);
  s.push(6);
  s.push(4);
  s.peek();
  s.pop();
  s.peek();
  s.isEmpty();
}