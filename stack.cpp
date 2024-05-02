#include <iostream>
#include <iostream>

using namespace std;
const int MAX_SIZE = 10;

template <class t>
class Stack{
  public:
  int top;
  t stack[MAX_SIZE];



Stack(){
  top = -1;
}

  public:

  void push(t element){
    if(top >= MAX_SIZE)
    return;
    else {
      top++;
      stack[top] = element;
    }
  }


  bool isempty(){
    return top < 0;
  }

  t pop(){
    if(isempty()){
      cout << "stack is empty\n";
      return 0;
    }else {
      top--;
    }
    return stack[top];
  }


  t peek(){
    return stack[top];
  }

  void print(){
    if(isempty()){
      cout << "nothing to print\n";
      return;
    }else {
      for(int i = top; i >= 0; i--){
        cout << stack[i] << endl;
      }
    }
  }


};

int main(){
  Stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.pop();
  cout << s.peek() << "\n";
  s.print();


return 0;
}