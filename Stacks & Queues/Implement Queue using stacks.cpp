#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define for0(i,n)   for ( int (i)=0; (i)<(n); (i)++)
#define for1(i,n)   for ( int (i)=1; (i)<=(n); (i)++)
typedef vector<int> vi;
#define pb push_back
#define OJ \
        freopen("input.txt", "r", stdin); \
        freopen("output.txt", "w", stdout);

// Implementation of Queue using 2 Stacks s1, s2
// Method : Dequeue operation is costly
// Strategy :- 
// Enqueue : push element in s1;
// Dequeue : pop element from s2
//           if s2 is empty then move all elements of s1 to s2, then pop from s2

stack<int> s1;
stack<int> s2;

void enqueue(int element){
  s1.push(element);
}

void dequeue(){
  if(s1.empty() && s2.empty())
    cout << "Queue is Empty\n";

  if(s2.empty()){
    while(!s1.empty()){
      s2.push(s1.top());
      s1.pop();
    }
  }
  int removed_element = s2.top();
  s2.pop();
  cout << removed_element << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  OJ;
  enqueue(5);
  enqueue(6);
  enqueue(3);
  dequeue();
  enqueue(9);
  dequeue();
}