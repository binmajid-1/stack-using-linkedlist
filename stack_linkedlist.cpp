#include <iostream>
using namespace std;
/*
operations on stack:
-push()
-pop()
-isempty()
-isfull()
-peek()
-search()
-count()
-display()
*/

class Node {
  public:
  int data;
  Node* next;
};

class Stack{
// top pointer
Node* top;

public:
// create stack
Stack(){
  top = NULL;
}
// isempty
bool isempty(){
  return(top == NULL);
}

// isfull
bool isfull(){
  Node* ptr = new Node();
  if(ptr == NULL)
  return true;
  else 
  return false;
}

// push => add element to end stack
void push(int value){
  Node* newnode = new Node();
  newnode->data = value;

  if(isempty()){
    newnode->next = NULL;
    top = newnode;
  }else {
    newnode->next = top;
    top = newnode;
  }
}

// pop => to delete last element in stack
int pop(){
  int value;
  Node* delptr = top;
  if(!isempty()){
  value = delptr->data;
  top = top->next;
  delete delptr;
  }else 
  cout << "stack is empty \n";

  return value;
}

// display
void display(){
  Node* temp = top;
  if(isempty())
  cout << "stack is empty \n";
  else {
  while(temp!= NULL){
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
  }
}

// count 
int count(){
  int counter = 0;
  Node* temp = top;
  while(temp != NULL){
    counter++;
    temp = temp->next;
  }
  return counter;
}

// peek => last element in stack
int peek(){
  int p = 0;
  p = top->data;
  return p;
}


// search 
bool isfound(int value){
  Node* temp = top;
  bool found = false;
  while(temp != NULL){
    if(temp->data == value){
      found = true;
      break;
    }
    temp = temp->next;
  }
  return found;
}

};



int main(){
  Stack s;
  int check;
  int item;
  while(true){
    cout << "\n================================\n";
    cout << "enter number 1 to push \n";
    cout << "enter number 2 to pop \n";
    cout << "enter number 3 to display last element \n";
    cout << "enter number 4 to search \n";
    cout << "enter number 5 to display count \n";
    cout << "enter number 6 to check isempty \n";
    cout << "enter number 7 to check isfull \n";
    cout << "\n================================\n";

    cin>> check;

    if(check == 1){
      cout << "enter item to push \n";
      cin>> item;
      s.push(item);
      s.display();
    }else if(check == 2){
      s.pop();
      s.display();
    }else if(check == 3){
      cout << s.peek() << endl;
    }else if(check == 4){
      cout << "enter item to search \n";
      cin>> item;
      if(s.isfound(item)){
        cout << item << " is found \n";
      }else 
      cout << item << " not found \n";
    }else if(check == 5){
      cout << "you have " <<s.count() << " elements\n";
    }else if(check == 6){
      if(s.isempty())
      cout << "your stack is empty \n";
      else 
      cout << "not empty \n";
    }else if(check == 7){
      if(s.isfull())
      cout << "stack is full\n";
      else 
      cout << "OK , stack not full \n";
    }else {
      cout << "invalid number \n";
    }
  }


  return 0;
}