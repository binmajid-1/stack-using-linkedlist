#include <iostream>
using namespace std;


  class Node{
    public:
    int data;
    Node *next;
    Node* prev;
  };

  class doubl_linkedlist{
    Node * first;
    Node * last;
    int count;

public:

    doubl_linkedlist(){
      first = last = NULL;
      count = 0;
    }

    bool isempty(){
      return (first == NULL && count == 0);
    }

    bool isfound(int item){
      bool found = false;
      Node* temp = first;
      while(temp!=NULL ){
        if(temp->data == item){
          found = true;
          break;
        }
        temp = temp->next;
      }
      return found;
    }

    void insertFirst(int item){
        Node* newnode = new Node();
        newnode->data = item;
      if(isempty()){
        first = last = newnode;
        newnode->next = newnode->prev = NULL;
        count++;
      }else {
        newnode->next = first;
        newnode->prev = NULL;
        first->prev = newnode;
        first = newnode;
        count++;
      }
      
    }


    void insertLast(int item){
              Node* newnode = new Node();
        newnode->data = item;
      if(isempty()){
                newnode->next = newnode->prev = NULL;
        first = last = newnode;
        count++;
      }else {
        newnode->prev = last;
        newnode->next = NULL;
        last->next = newnode;
        last = newnode;
        count++;
      }
    }


    void insert(int index,int item){
      if(!isfound(index)){
        cout << "item not found you want to insert before\n ";
        return;
      }
      Node* newnode = new Node();
      newnode->data = item;
      if(isempty()){
        newnode->next = newnode->prev = NULL;
        first = last = newnode;
        count++;
      }else if(index == first->data){
      insertFirst(item);
      count++;
      }
      else if(index == last->data){
      insertLast(item);
      count++;
      }
      else{
        Node* temp = first;
        while(temp != NULL && temp->next->data != index){
          temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
        count++;
      }
    }



    void remove(int item){
      Node*temp = first;
      Node*pre = NULL;
      if(first->next == NULL){
        delete first;
        first = last = NULL;
        count--;
      }else if(item == first->data){
        temp = first;
        first = first->next;
        first->prev = NULL;
        delete temp;
        count--;
      }else if(item == last->data){
        temp = last;
        last = last->prev;
        last->next = NULL;
        delete temp;
        count--;
      }else {
      while(temp->next != NULL && temp->data != item ){
        pre = temp;
        temp = temp->next;
      }
      pre->next = temp->next;
      temp->next->prev = pre;
      delete temp;
      count--;
      }

    }


    void display(){
      Node * temp = first;
      if(isempty()){
        cout << "no elements\n";
        return;
      }

      cout << "Elements : [ ";
      for(int i = 0; i < count; i++){
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << " ]\n";

    }


  };


int main(){
  doubl_linkedlist d1;
d1.insertLast(10);
d1.insertLast(20);
d1.remove(20);
d1.insertLast(30);
  d1.display();
d1.insert(20,40);
d1.insertLast(90);
d1.insertFirst(0);
  d1.display();
  return 0;
}