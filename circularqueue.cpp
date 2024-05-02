#include <iostream>
#include <assert.h>
using namespace std;

template <class t>

class circlequeue
{
private:
  int front;
  int rear;
  int length;
  int maxsize;
  t *arr;

public:
  circlequeue(int size)
  {
    if (size <= 0)
      size = 100;
    else
      maxsize = size;

    front = 0;
    rear = maxsize - 1;
    arr = new t[maxsize];
    length = 0;
  }

  bool isempty(){
    return length == 0;
  }

  int isfull(){
    return length == maxsize;
  }


  void enqueue(t item){
    if(!isfull()){
      rear = (rear + 1)% maxsize;
      arr[rear] = item;
      length++;
    }else {
      cout << "queue is full\n";
    }
  }

  t dequeue(){
    t item;
    if(!isempty()){
      item = arr[front];
      front = (front + 1)% maxsize;
      length--;
    }else {
      cout << "queue is empty\n";
    }
    return item;
  }


  t getfront(){
    assert(!isempty());
    return arr[front];
  }


  t getrear(){
    t r ;
    if(!isempty())
    r = arr[rear];
    else 
    cout << "queue is empty no rear ...\n ";

    return r;
  }


  int search(t item){
    int index = -1;
    if(isempty()){
      cout << "empty nothing to search\n";
      return 0;
    }else {
      for (int i = front; i != rear; i= (i + 1)%maxsize )
      {
        if(item == arr[i]){
          index = i;
          break;
        }
      }
      if(index == -1){
        if(item == arr[rear]){
          index = rear;
        }
      }
      
    }

    return index;
  }



  void queueprint(){
    if(isempty()){
      cout << "nothing to print ...\n";
      return;
    }else {
      cout << "[ ";
      for (int i = front; i != rear; i= (i + 1)%maxsize )
      {
        cout << arr[i] << " ";
      }
      cout << arr[rear] << " ";
      cout << " ]\n";
    }
  }



  void clearqueue(){
    if(!isempty()){
    dequeue();
    clearqueue();
    }
    else 
    cout << "clear queue is empty\n";
  }




};

int main()
{
  circlequeue<int> q1(5);
  q1.enqueue(10);
  q1.enqueue(10);
  q1.enqueue(10);
  q1.enqueue(10);
  q1.clearqueue();
  q1.queueprint();


// if(q1.search(50) == -1)
// cout << "item not found\n";
// else if(q1.search(50) == 0)
// return 0;
// else 
// cout << "item founded at index: " << q1.search(50) << endl;


  return 0;
}