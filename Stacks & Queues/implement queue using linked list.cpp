//By Manish Kumar

#include<bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;

void queuex(int data) {
  struct node* temp;
  temp = new node();
  if(!temp){
    cout << "Queue is Overflow";
  }
  else {
    temp->data = data;
    if(front == NULL){
      front = temp;
      rear = temp;
    }
    else {
      rear->next = temp;
      rear = temp;
    }
  }
}

void dequeue() {
  struct node* temp;
  if(rear == NULL){
    cout << "Queue is Underflow";
  }
  else {
    temp = front;
    front = front->next;
    free(temp);
  }
}

void display() {
  struct node* temp;
  if(rear == NULL){
    cout << "Queue is Undrflow";
  }
  else {
    temp = front;
    while(temp != NULL){
      cout << temp->data << " ";
      temp = temp->next;
    }
  }
}

int main(){
  queuex(25);
  queuex(23);
  dequeue();
  display();
}





