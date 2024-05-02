#include <iostream>
using namespace std;
template <class t>

class Array{
  private:
  int length,size;
  t* arr;


  public:
  Array(int s){
    size = s;
    arr = new t[size];
    length = 0;
  }



  //IsEmpty
  bool isEmpty(){
    return(length == 0);
  }

  //is full
  bool isFull(){
    return(length == size);
  }


  // Add or append
  void add(t item){
    if(!isFull()){
      arr[length] = item;
      length++;
    }else{
      cout << "array is full\n";
    }
  }

    //fill
    void Fill(){
    int no_of_items;
    cout << "How many items you want fill \n";
    cin>> no_of_items;
    if(no_of_items > size)
    {
      cout << "please enter items less of array size \n";
    }else if(no_of_items <= size) {
  for(int i = 0; i < no_of_items; i++){
    cout << "enter the item no " << i + 1 << "\n";
    cin>>arr[i];
    length++;
  }
    }
  }


  // insert
  void insert(int index,t item){
    if(index >= size || index < 0)
    return;

    if(!isFull()){
      for(int i = length; i > index; i--){
        arr[i] = arr[i-1];
      }
      arr[index] = item;
      length++;
    }else 
    cout << "full array\n";
  }

  //delete
  t Delete(int index){
    
    if(!isEmpty()){
    if(index >=0 && index <= length)
    {
      t temp = arr[index];
      for(int i = index; i < length -1; i++){
        arr[i] = arr[i+1];
      }
      length--;
    }
    }else 
    cout << "empty array\n";
  }


  // display
  void display(){
    if(!isEmpty()){
      cout << "[ ";
      for(int i = 0; i < length; i++){
        cout << arr[i] << " ";
      }
      cout << " ]\n";
    }else 
    cout << "empty array\n";
  }

  // search
  int search(t item){
    int index = -1;
    if(!isEmpty()){
      for(int i = 0; i < length; i++){
        if(item == arr[i]){
          index = i;
          break;
        }
      }
    }
    return index;
  }



  //getsize
    int getSize(){
    return size;
  }

  //get length
    int getLength(){
    return length;
  }


  //reverse
  t reverse(){
      t rev[size];
    if(!isEmpty()){
      for(int i = 0; i < length; i++){
        rev[i] = arr[size - i - 1];
      }
    }
    return rev;
  }

  //Elarge
  void elarge(int newsize){
    t *old = arr;
    if(newsize > size){
      size = newsize;
      arr = new t[size];
      for(int i = 0; i < length; i++){
        arr[i] = old[i];
      }
      delete old;
    }else 
    cout << "size must be larger than old size\n";
  }

};



class algorthim{
  public:
  void  bubleSort(int arr[],int length){
    bool isSwapped = true;
    int i = 0; 
    while(isSwapped){
      isSwapped = false;
      for(int j = 0; j < length - i; j++ ){
        if(arr[j] > arr[j+1]){
          int temp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = temp;
          isSwapped = true;
        }
      }
      i++;
    }
  }






  void selectionSort(int arr[],int length){
    int i;
    int j;
    for(i = 0; i < length; i++){
    int min = i;
      for(j = i+1; j < length; j++){
        if(arr[min] > arr[j]){
        min = j;
        }
      }
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
      
    }
  }
};

int main(){
  algorthim a;
  int ar[] = {34,45,2,5,66,1,56,6,2,0};
  int si = sizeof(ar) / sizeof(ar[0]);
  a.selectionSort(ar,si);
  

  for(int i = 0; i < si; i++){
    cout << ar[i] << " ";
  }
  cout << endl;
  return 0;
}