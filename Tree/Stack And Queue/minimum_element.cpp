#include<bits/stdc++.h>

using namespace std;

class _stack {
  stack<int> s;
  int minEle;
  public :
    int getMin();
    int pop();
    void push(int);
};

int main() {
  int t;
  cin>>t;
  while(t--)
  {
    int q;
    cin>>q;
    _stack *a = new _stack();
    while(q--){
    int qt;
    cin>>qt;
    if(qt==1)
    {
      int att;
      cin>>att;
      a->push(att);
    }
    else if(qt==2)
    {
      cout<<a->pop()<<" ";
    }
    else if(qt==3)
    {
      cout<<a->getMin()<<" ";
    }
    }
    cout<<endl;
  }
}

/*This is a function problem.You only need to complete the function given below*/
/*
  The structure of the class is as follows
  class _stack{
  stack<int> s;
  int minEle;
  public :
      int getMin();
      int pop();
      void push(int);
  };
*/

/*returns min element from stack*/
int _stack :: getMin(){
  return s.empty() ? -1 : s.top() % 101;
}

/*returns poped element from stack*/
int _stack ::pop() {
  if (s.empty()) return -1;

  int result = s.top() / 101;

  s.pop();
  
  return result;
}

/*push element x into the stack*/
void _stack::push(int x) {
  int currentMin = s.empty() ? x : s.top() % 101;

  s.push(x * 101 + min(currentMin, x));
}
