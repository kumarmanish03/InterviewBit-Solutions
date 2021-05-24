// Manish Kumar, IIIT Allahabad
// Medium, Classes and Objects
// Time Complexity : O(1)
// Space Complexity : O(n)

https://www.interviewbit.com/problems/min-stack/

https://www.geeksforgeeks.org/c-classes-and-objects/
// Do read the above article(Constructor, destructor, Copy Constructor, etc)

// Must do Question
// This is an important question, as it is using Classes, Objects, Constructors, Stack
// Catch! in this ques is Constructor, since constructor is called when an object is intialized
// Hence, you have to re-initialize all global information in constructor



stack<int> s;
stack<int> ms;
MinStack::MinStack() {
  while(!s.empty()){
      s.pop();
  }
  while(!ms.empty()){
      ms.pop();
  }
}

void MinStack::push(int x) {
    s.push(x);
    if(ms.empty()){
        ms.push(x);
    }
    else if(x < ms.top()){
        ms.push(x);
    }
}

void MinStack::pop() {
    if(!s.empty()){
        if(ms.top() == s.top()){
            ms.pop();
        }
        s.pop();
    }
}

int MinStack::top() {
    if(s.empty())
        return -1;
    else
        return s.top();
}

int MinStack::getMin() {
    if(ms.empty()){
        return -1;
    }
    return ms.top();
}

