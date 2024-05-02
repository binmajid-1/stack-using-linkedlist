#include <iostream>
#include <string>
#include <stack>
#include <openssl/aes.h>
using namespace std;

bool ispaird(char open,char close){
  if(open == '(' && close == ')')
  return true;
  else if (open == '[' && close == ']')
  return true;
  else if (open == '{' && close == '}')
  return true;

  else return false;
}





bool AreBalanced(string exp){
  stack<char> s;

  for (size_t i = 0; i < exp.length(); i++)
  {
    if(exp[i] == '('||exp[i] == '['||exp[i] == '{')
    s.push(exp[i]);
    else if (exp[i] == ')'||exp[i] == ']'||exp[i] == '}')
    {
      if(s.empty() || !ispaird(s.top(),exp[i]))
      return false;
    }else {
      s.pop();
    }
  }

  return(s.empty());
  
}


int odd_count(int n){
  int count = 0;
  int num = n;
  while(num>1){
    if(num % 2 == 1)
      count++;
    num--;
  }
  
  return count;
}




int main(){




  return 0;
}