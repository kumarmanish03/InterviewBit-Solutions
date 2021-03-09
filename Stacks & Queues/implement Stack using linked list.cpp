#include<bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node* link;
};
struct node* top;

int push(int data) {
  struct node* temp;
  temp = new node();

  if(!temp){
    cout << "stack is full";
  }
  else {
    temp->data = data;
    temp->link = top;
    top = temp;
  }
}

int isEmpty(){
  return top==NULL;
}

int peek() {
  if(top == NULL){
    cout << "Stack is Empty";
  }
  else {
    cout << top->data;
  }
}

int pop() {
  struct node* temp;

  if(top == NULL){
    cout << "Stack is Empty";
  }
  else {
    temp = top;
    top = top->link;
    temp->link = NULL;
    free(temp);
  }
}

int main() {
  push(12);
  push(15);
  peek();
  pop();
  peek();
  pop();
  cout << isEmpty();
}